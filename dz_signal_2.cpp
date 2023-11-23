#include <iostream>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
   int sig = atoi(argv[1]);
   pid_t pid = atoi(argv[2]);
   kill(pid,sig);
   return 0;
}
