#include <iostream>
#include <signal.h>
#include <stdlib.h>

int i = 0;

void ignor_sigusr1(int sig) {

}

void ignor_sigusr2(int sig) {
   std::cout << " saf " ;
    ++i;
}

void finish(int sig){
  std::cout << "signal SIGUSER2 was received " << i << " times" << std::endl;
  exit(EXIT_SUCCESS);
}

int main() {
  if(signal(SIGUSR1,ignor_sigusr1) == SIG_ERR){
    perror("signal faield");
    exit(EXIT_FAILURE);
  }
  if(signal(SIGUSR2,ignor_sigusr2) == SIG_ERR){
    perror("signal faield");
    exit(EXIT_FAILURE);
  }
  if(signal(SIGINT,finish) == SIG_ERR){
    perror("signal faield");
    exit(EXIT_FAILURE);
  }
while(true){
	std::cout << "I am still alive!!!" << std::endl;
     sleep(5);
  }  
}
