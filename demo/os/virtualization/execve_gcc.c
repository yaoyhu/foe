#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 0) exit(EXIT_FAILURE);
  if (pid == 0) {
    char *argv[] = {"gcc", "execve-gcc.c", "-o", "execve-gcc", NULL};
    char *envp[] = {
        "PATH=/opt/homebrew/bin:"
        "/opt/homebrew/opt/binutils/bin:"
        "/opt/homebrew/Cellar/gcc/14.1.0_1/libexec/gcc/aarch64-apple-darwin23/14:"
        "/usr/bin",
        "LIBRARY_PATH=/opt/homebrew/Cellar/gcc/14.1.0_1/lib/gcc/current/gcc",
        NULL};

    if (execve("/opt/homebrew/bin/gcc-14", argv, envp) == -1)
      _exit(EXIT_FAILURE);
    _exit(0);
  } else {
    wait(NULL);
    _exit(0);
  }
  return 0;
}
