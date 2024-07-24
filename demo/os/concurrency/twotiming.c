#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef int GIRL;
GIRL girl = 0;  // 0 for single, 1 for taken, 2 for bitch

void* date(void* args) {
  if (girl == 0) {
    // Bugs may only manifest on specific timings. Sometimes
    // we reproduce bugs by inserting sleep()s.
    usleep(1);
    girl++;
  }
  return NULL;
}

int main() {
  pthread_t p1, p2;

  pthread_create(&p1, NULL, date, NULL);
  pthread_create(&p2, NULL, date, NULL);

  pthread_join(p2, NULL);
  pthread_join(p1, NULL);

  if (girl == 2) printf("I am a totally bitch!\n");

  return 0;
}
