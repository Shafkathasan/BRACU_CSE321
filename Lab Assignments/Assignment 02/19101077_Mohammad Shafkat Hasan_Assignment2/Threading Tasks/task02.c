//Mohammad Shafkat Hasan
//ID: 19101077
//Threading Tasks
//Task02

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Question:
Write a program in c using 5 threads where each thread will print 5 integers
The outputs will look like this:
Thread 1: 1 2 3 4 5
Thread 2: 6 7 8 9 10
Thread 3: 11 12 13 14 15
Thread 4: 16 17 18 19 20
Thread 5: 21 22 23 24 25
*/

// Thread function
void *thread_function(void *arg)
{
    int *id = (int *)arg;
    for (int i = 0; i < 5; i++)
    {
        if (*id == 1)
        {
            printf("Thread %d prints %d\n", *id, i + 1);
        }
        else if (*id == 2)
        {
            printf("Thread %d prints %d\n", *id, i + 6);
        }
        else if (*id == 3)
        {
            printf("Thread %d prints %d\n", *id, i + 11);
        }
        else if (*id == 4)
        {
            printf("Thread %d prints %d\n", *id, i + 16);
        }
        else if (*id == 5)
        {
            printf("Thread %d prints %d\n", *id, i + 21);
        }
    }
    pthread_exit(NULL);
}

// Main function
int main()
{
    pthread_t thread_id[5];
    int i;
    int *id;
    for (i = 0; i < 5; i++)
    {
        id = (int *)malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&thread_id[i], NULL, thread_function, id);
        pthread_join(thread_id[i], NULL);
    }
    return 0;
}

