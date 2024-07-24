#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf("&code: %p\n", (void*)main);
  printf("&heap: %p\n", (void*)malloc(1));
  int x = 3;
  printf("&stack: %p\n", &x);
  return 0;
}