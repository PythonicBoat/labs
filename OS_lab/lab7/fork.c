#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == -1) {
        perror("Error creating child process");
        return 1;
    } else if (child_pid == 0) {
        printf("Hello from the child process! (PID: %d)\n", getpid());
    } else {
        printf("Hello from the parent process! (PID: %d)\n", getpid());
    }

    return 0;
} 
