//Mohammad Shafkat Hasan
//ID: 19101077
//System Call Tasks
//Task04

#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char *argv[]) {
    int arr[argc-1];
    for(int i=0; i<argc-1; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    int n = argc-1;
    qsort(arr, n, sizeof(int), compare);
    printf("Sorted array in descending order: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

