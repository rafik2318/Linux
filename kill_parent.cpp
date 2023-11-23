#include <iostream>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  pid_t pid = fork();
  if(pid == -1){
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0){
	sleep(1);
      std::cout << "Child pid" << getpid() << std::endl;
      std::cout << "My parent pid" << getppid() << std::endl;
      if(kill(getppid(),SIGKILL) == 0){
 	std::cout << "Parent die" << std::endl;
      } else {
        std::cout << "Parent alive" << std::endl;
	} 
  } else {
    wait(NULL);
    std::cout << "Parent pid" << getpid() << std::endl;
  }
  return 0;
}
