//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task03

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Question:
Consider the following code snippet in your main function -

a = fork();
b = fork();
c = fork();

Now, write the full program, that will check the children’s PID for odd or even and if it is odd then the process
will create another child process. Lastly, print how many processes have been created
considering the first parent process.
*/

int main() {
    int a, b, c;
    int process_count = 1; // initialize process count to 1 for the first parent process

    a = fork();
    b = fork();
    c = fork();

    if (a == 0) {
        // child process a
        if (getpid() % 2 != 0) {
            // PID is odd, create another child process
            fork();
            process_count++;
        }
    } else if (b == 0) {
        // child process b
        if (getpid() % 2 != 0) {
            // PID is odd, create another child process
            fork();
            process_count++;
        }
    } else if (c == 0) {
        // child process c
        if (getpid() % 2 != 0) {
            // PID is odd, create another child process
            fork();
            process_count++;
        }
    } else {
        // parent process
        process_count += 3; // add 3 for the child processes created by fork()

        printf("Total number of processes created: %d\n", process_count);
    }

    return 0;
}
