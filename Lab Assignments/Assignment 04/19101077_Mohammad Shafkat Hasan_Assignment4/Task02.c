//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 04
//Task02

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution using mutex and semaphore.
use 5 Fsrmers and 5 ShopOwner to demonstrate the solution.
*/

#define MaxCrops 5      // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'};     // indicatig room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; // initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *far)
{
    //
    //    1.Farmer harvest crops and put them in perticular room. For example, room 0 for Rice(R).
    //    2.use mutex and semaphore for critical section.
    //    3.print which farmer is keeping which crops in which room inside the critical section.
    //    4.print the whole warehouse buffer outside of the critical section

    // Write code here
    int i;
    int *farmer_id = (int *)far;
    for (i = 0; i < MaxCrops; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in] = crops[*farmer_id];
        printf("Farmer %d: Insert crops %c at %d\n", *farmer_id, warehouse[in], in);
        in = (in + 1) % warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    printf("\nFarmer: %d", *farmer_id);
    for (i = 0; i < warehouseSize; i++)
    {
        printf("%c", warehouse[i]);
    }
    printf("\n");
    return 0;
}
void *ShopOwner(void *sho)
{
    /*
       1.Shop owner take crops and make that perticular room empty.
       2.use mutex and semaphore for critical section.
       3.print which shop owner is taking which crops from which room inside the critical section.
       4.print the whole warehouse buffer outside of the critical section
       */
    // Write code here

    int i;
    int *shop_id = (int *)sho;
    for (i = 0; i < MaxCrops; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        warehouse[out] = warehouse[*shop_id];
        printf("Shop owner %d: Remove crops %c from %d\n", *shop_id, warehouse[out], out);
        out = (out + 1) % warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    printf("\nShop owner %d: ", *shop_id);
    for (i = 0; i < warehouseSize; i++)
    {
        printf("%c", warehouse[i]);
    }
    printf("\n");
    return 0;
}

int main()
{

    /*intializing thread,mutex,semaphore
     */

    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);

    int a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&Far[i], NULL, (void *)Farmer, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&Sho[i], NULL, (void *)ShopOwner, (void *)&a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(Far[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(Sho[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
