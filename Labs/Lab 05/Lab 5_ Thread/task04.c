#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        // Fork failed
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        // This is the child process
        printf("I am child\n");

        // Create a grandchild process
        grandchild_pid = fork();

        if (grandchild_pid == -1) {
            // Fork failed
            perror("fork");
            return 1;
        } else if (grandchild_pid == 0) {
            // This is the grandchild process
            printf("I am grandchild\n");
            return 0;
        } else {
            // This is the child process again
            wait(NULL); // Wait for the grandchild process to finish
            return 0;
        }
    } else {
        // This is the parent process
        wait(NULL); // Wait for the child process to finish
        printf("I am parent\n");
        return 0;
    }
}
