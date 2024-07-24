#include <assert.h>
#include <pthread.h>
#include <stdio.h>

typedef struct {
  pthread_t p1;
  pthread_t p2;
} THREADS;

int command = 0;
pthread_mutex_t spinlock = PTHREAD_MUTEX_INITIALIZER;

void* commander(void* arg) {
  THREADS* threads = (THREADS*)arg;
  pthread_mutex_lock(&spinlock);
  printf("同志们好！\n");
  command++;
  pthread_mutex_unlock(&spinlock);

  assert((pthread_join(threads->p1, NULL)) == 0);

  pthread_mutex_lock(&spinlock);
  printf("同志们幸苦了！\n");
  command++;
  pthread_mutex_unlock(&spinlock);
  return NULL;
}

void* child1(void* arg) {
  // busy waitting using while
  while (1) {
    pthread_mutex_lock(&spinlock);
    if (command != 1) {
      pthread_mutex_unlock(&spinlock);
      continue;
    }
    assert(command == 1);
    printf("主席好！\n");
    pthread_mutex_unlock(&spinlock);
    break;
  }
  return NULL;
}

void* child2(void* arg) {
  // busy waitting using goto
retry:
  pthread_mutex_lock(&spinlock);
  if (command != 2) {
    pthread_mutex_unlock(&spinlock);
    goto retry;
  }
  assert(command == 2);
  pthread_mutex_unlock(&spinlock);
  printf("为人民服务！\n");

  return NULL;
}

int main(int argc, char* argv[]) {
  pthread_t president, soldier1, soldier2;
  // Please create soldier1 before president!
  pthread_create(&soldier1, NULL, child1, NULL);
  pthread_create(&soldier2, NULL, child2, NULL);
  // Please init the threads after the soldier1 created
  THREADS threads = {.p1 = soldier1, .p2 = soldier2};
  pthread_create(&president, NULL, commander, &threads);
  pthread_join(soldier2, NULL);
  pthread_join(president, NULL);
  return 0;
}