//Mohammad Shafkat Hasan
//ID: 19101077
//Threading Tasks
//Task01

#include <stdio.h>
#include <pthread.h>

/*
Question:
Write a c program that creates 5 threads and prints which thread is running and after the thread is
closed, a new thread starts its execution. Each thread should run sequentially one by one.
*/

#define NUM_THREADS 5

// Thread function
void* thread_func(void* arg) {
    int thread_num = *((int*) arg);
    printf("thread-%d running\n", thread_num);
    printf("thread-%d closed\n", thread_num);
    return NULL;
}

// Main function
int main() {
    pthread_t threads[NUM_THREADS];
    int thread_nums[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_nums[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, (void*) &thread_nums[i]);
        pthread_join(threads[i], NULL);
    }

    return 0;
}


