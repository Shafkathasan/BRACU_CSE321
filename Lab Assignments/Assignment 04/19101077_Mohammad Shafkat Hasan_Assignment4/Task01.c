//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 04
//Task01

#include <pthread.h>   
#include <stdio.h>
#include <string.h>

#define MAX 10 //producers and consumers can produce and consume up to MAX
#define BUFLEN 6
#define NUMTHREAD 2      /* number of threads */

void *consumer(void *id);
void *producer(void *id);

char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0, 1};
int i = 0;
int j = 0;

int main()
{
    int i;
    /* define the type to be pthread */
    pthread_t thread[NUMTHREAD];

    strcpy(source, "abcdef");
    buflen = strlen(source);
    /* create 2 threads*/
    /* create one consumer and one producer */
    /* define the properties of multi threads for both threads  */
    pthread_create(&thread[0], NULL, producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, consumer, &thread_id[1]);

    /* wait for the threads to finish */
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}


void *producer(void *id)
{
    int *producer_id = (int *)id;
    while (pCount < MAX)
    {
        pthread_mutex_lock(&count_mutex); // acquire lock before entering critical section
        while (j >= BUFLEN) // check if buffer is full
        {
            pthread_cond_wait(&full, &count_mutex); // wait until buffer is not full
        }

        buffer[j] = source[pCount % buflen]; // copy from source to buffer
        printf("%d produced  %c  by Thread  %d\n", pCount, buffer[j], *producer_id);
        j++;
        pCount++;

        pthread_mutex_unlock(&count_mutex); // release lock after exiting critical section
        pthread_cond_signal(&nonEmpty); // signal that buffer is not empty
    }
    pthread_exit(NULL);
}

void *consumer(void *id)
{
    int *consumer_id = (int *)id;
    while (cCount < MAX)
    {
        pthread_mutex_lock(&count_mutex); // acquire lock before entering critical section
        while (j <= 0) // check if buffer is empty
        {
            pthread_cond_wait(&nonEmpty, &count_mutex); // wait until buffer is not empty
        }

        char val = buffer[j-1]; // consume the last value from the buffer
        printf("%d consumed  %c  by Thread  %d\n", cCount, val, *consumer_id);
        j--;
        cCount++;

        pthread_mutex_unlock(&count_mutex); // release lock after exiting critical section
        pthread_cond_signal(&full); // signal that buffer is not full
    }
    pthread_exit(NULL);
}

