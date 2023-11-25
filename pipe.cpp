#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    pid_t child1, child2;
    child1 = fork();

    if (child1 == 0) {
        close(pipefd[0]);

        pid_t child1 = getpid();
        write(pipefd[1], &child1, sizeof(child1));
        close(pipefd[1]);

        std::cout <<"Child1 pid is " << child1 << std::endl;

        return 0;
    }

    child2 = fork();
    if (child2 == 0) {
        close(pipefd[0]); 

        pid_t child2 = getpid();
        write(pipefd[1], &child2, sizeof(child2));
        close(pipefd[1]);

        std::cout << "Child2 pid is " << child2 << std::endl;

        return 0;
    }
close(pipefd[1]);
    pid_t child1_pid, child2_pid;
    read(pipefd[0], &child1_pid, sizeof(child1_pid));
    read(pipefd[0], &child2_pid, sizeof(child2_pid));
    close(pipefd[0]);

    std::cout << "child1 pid " << child1_pid << std::endl;
    std::cout << "child2 pid " << child2_pid << std::endl;

    wait(NULL);
    wait(NULL);

    return 0;
}
