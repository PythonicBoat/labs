// Write a c program to create different processes using fork() system call

#include <stdio.h>
#include <unistd.h>

int main() {
    int num_processes = 5; 
    
    printf("Parent process with PID %d\n", getpid());

    for (int i = 0; i < num_processes; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) {
            printf("Child process with PID %d and parent PID %d\n", getpid(), getppid());
            break; 
        } 
    }
    return 0;
}
