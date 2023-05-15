//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task04

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Question:
Write a program that will create a child process and the child process will first
sort the array that you have declared in this program. And then, the parent process will print the
odd/even status for each number in the array.
*/

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char *argv[]) {
    int arr[argc-1];
    for(int i=0; i<argc-1; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    int n = argc-1;

    pid_t pid = fork();

    if(pid == 0) {
        // Child process
        qsort(arr, n, sizeof(int), compare);
        printf("Sorted array in descending order: ");
        for(int i=0; i<n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Parent process
        wait(NULL);
        printf("Odd/Even status of the numbers: ");
        for(int i=0; i<n; i++) {
            int num = arr[i];
            if(num % 2 == 0) {
                printf("Even ");
            } else {
                printf("Odd ");
            }
        }
        printf("\n");
    }

    return 0;
}

/* Bash sample commands:
# Compile sort.c
gcc -o sort sort.c

# Run sort.c with some numbers as command line arguments
./sort 5 2 8 1 6

# Compile oddeven.c
gcc -o oddeven oddeven.c

# Run oddeven.c with some numbers as command line arguments
./oddeven 5 2 8 1 6

# Compile parent_child.c
gcc -o parent_child parent_child.c

# Run parent_child.c with some numbers as command line arguments
./parent_child 5 2 8 1 6
*/
