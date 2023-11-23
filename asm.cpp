#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void handler(int sig) {
    std::cout << "The sender process pid is " << getpid() << std::endl;
    unsigned int eax, ebx, eip;
//    asm volatile ("movl %%eip, %0"  : "=r" (eip));
        asm volatile ("movl %%eax, %0" : "=r" (eax));
        asm volatile ("movl %%ebx, %0" : "=r" (ebx));
std::cout << "EIP,EAX,EBX are" << eax << "," << ebx << "," << eip  << std::endl;
exit(EXIT_SUCCESS);
}


int main() {
   std::cout << "My pid is " << getpid() << std::endl;
  if(signal(SIGUSR2,handler) == SIG_ERR){
	std::cout << " sfa ";
    perror("signal faield");
    exit(EXIT_FAILURE);
  }

  while(1){
    sleep(10);
  }
  
}
