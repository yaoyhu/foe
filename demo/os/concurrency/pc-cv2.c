#include <assert.h>
#include <pthread.h>
#include <stdio.h>

#define CAN_PRODUCE (depth < 3)
#define CAN_CONSUME (depth > 0)

int depth = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;

void* T_producer(void* args) {
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&lock);
    while (!CAN_PRODUCE) {  // can not produce
      pthread_cond_wait(&empty, &lock);
    }
    assert(CAN_PRODUCE);
    printf("(");
    depth++;
    pthread_cond_signal(&fill);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

void* T_consumer(void* args) {
  for (int i = 0; i < 5; i++) {
    pthread_mutex_lock(&lock);
    while (!CAN_CONSUME) {
      pthread_cond_wait(&fill, &lock);
    }
    assert(CAN_CONSUME);
    printf(")");
    depth--;
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main(int argc, char* argv[]) {
  pthread_t producer, consumer1, consumer2;
  pthread_create(&producer, NULL, &T_producer, NULL);
  pthread_create(&consumer1, NULL, &T_consumer, NULL);
  pthread_create(&consumer2, NULL, &T_consumer, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer1, NULL);
  pthread_join(consumer2, NULL);
  return 0;
}
