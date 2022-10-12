// Q1: 2432902008176640000

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  pid_t pid = fork();
  if (pid == 0) {
    printf("Child created\n");
    while(1); //infinite loop
    printf("this line should not be shown\n");
    exit(0);
  } else {
    sleep(2);
    printf("sending SIGKILL\n");
    kill(pid, SIGKILL);
  }
  return 0;
} 