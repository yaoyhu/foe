#include <stdlib.h>

#define GiB *(1024LL * 1024 * 1024)

int main() {
  char* msg = (char*)malloc(32 GiB);
  free(msg);
  return 0;
}