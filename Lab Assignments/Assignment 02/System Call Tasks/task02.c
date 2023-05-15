//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task02

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Question:
Write a program that will create a child and another grandchild process. Every process will print
a line.

Parent process will print, “I am parent”
Child process will print, “I am child”
Grandchild process will print, “I am grandchild”

Now, write the program in such way so that the following output will be shown -
I am grandchild
I am child
I am parent
*/

int main() {
    // create child process
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // child process
        pid_t grandchild_pid = fork();

        if (grandchild_pid == 0) {
            // grandchild process
            printf("I am grandchild\n");
        } else {
            // child process
            wait(NULL);
            printf("I am child\n");
        }
    } else {
        // parent process
        wait(NULL);
        printf("I am parent\n");
    }

    return 0;
}

