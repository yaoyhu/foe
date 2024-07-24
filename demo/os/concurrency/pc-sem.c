#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t full, empty;

void* T_producer(void* args) {
  for (int i = 0; i < 10; i++) {
    sem_wait(&empty);
    printf("(");
    sem_post(&full);
  }
  return NULL;
}

void* T_consumer(void* args) {
  for (int i = 0; i < 10; i++) {
    sem_wait(&full);
    printf(")");
    sem_post(&empty);
  }
  return NULL;
}

int main(int argc, char* argv[]) {
  pthread_t producer, consumer;
  // sem_init is deprecated in macOS!!!
  sem_init(&empty, 0, 1);
  sem_init(&full, 0, 0);
  pthread_create(&producer, NULL, &T_producer, NULL);
  pthread_create(&consumer, NULL, &T_consumer, NULL);
  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);
  return 0;
}