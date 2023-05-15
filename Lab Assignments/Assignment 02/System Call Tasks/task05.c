//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task05

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*
Question:
Write a program in c that the parent process will create one child process and 3 grandchild
processes and print their IDs
Output: 1. Parent process ID : 0
2. Child process ID : ...
3. Grand Child process ID: ...
4. Grand Child process ID: ...
5. Grand Child process ID: ...
*/

int main() {
    pid_t pid, child_pid, grandchild_pid1, grandchild_pid2, grandchild_pid3;

    pid = getpid(); // Get parent process ID

    printf("1. Parent process ID: %d\n", pid);

    // Create child process
    child_pid = fork();

    if (child_pid == 0) { // Child process
        pid = getpid(); // Get child process ID
        printf("2. Child process ID: %d\n", pid);

        // Create three grandchild processes
        grandchild_pid1 = fork();

        if (grandchild_pid1 == 0) { // Grandchild process 1
            pid = getpid(); // Get grandchild process ID
            printf("3. Grandchild process ID: %d\n", pid);
            return 0;
        }

        grandchild_pid2 = fork();

        if (grandchild_pid2 == 0) { // Grandchild process 2
            pid = getpid(); // Get grandchild process ID
            printf("4. Grandchild process ID: %d\n", pid);
            return 0;
        }

        grandchild_pid3 = fork();

        if (grandchild_pid3 == 0) { // Grandchild process 3
            pid = getpid(); // Get grandchild process ID
            printf("5. Grandchild process ID: %d\n", pid);
            return 0;
        }

        return 0;
    }

    return 0;
}

