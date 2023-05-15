//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task04

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Odd/Even status of the numbers: ");
    for(int i=1; i<argc; i++) {
        int num = atoi(argv[i]);
        if(num % 2 == 0) {
            printf("Even ");
        } else {
            printf("Odd ");
        }
    }
    printf("\n");
    return 0;
}

