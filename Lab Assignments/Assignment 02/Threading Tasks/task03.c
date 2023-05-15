//Mohammad Shafkat Hasan
//ID: 19101077
//Threading Tasks
//Task03

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*
Question:
Write a program in c that has a function that takes the name of the user and adds all the ASCII
value of the characters and returns it. Now create 3 threads that run the function using 3 different
user names. Now print “Youreka” if all the returned values are equal, print “Miracle” if any 2
returned values are equal and print “Hasta la vista” if the values don’t match using another
thread.
*/

// function to add all the ASCII values of the characters
void *count_ascii(void *arg)
{
    char *name = (char *)arg;
    int i = 0, sum = 0;
    int *result = (int *)malloc(sizeof(int));
    while (name[i] != '\0')
    {
        sum += name[i];
        // printf("%c", name[i]);
        // printf("%d", sum);
        i++;
    }
    // prinnf("%s: %d\n", name, sum);
    *result = sum;
    return result;
}

// main function
int main()
{
    pthread_t t1, t2, t3;
    char *name1 = "Iftekhar";
    char *name2 = "Hossain";
    char *name3 = "Turja";
    int *result1, *result2, *result3;

    // create 3 threads to run the function
    pthread_create(&t1, NULL, count_ascii, (void *)name1);
    pthread_join(t1, (void **)&result1);
    pthread_create(&t2, NULL, count_ascii, (void *)name2);
    pthread_join(t2, (void **)&result2);
    pthread_create(&t3, NULL, count_ascii, (void *)name3);
    pthread_join(t3, (void **)&result3);

    // compare the results and print the appropriate message
    if (*result1 == *result2 && *result1 == *result3)
    {
        printf("Youreka\n");
    }
    else if (*result1 == *result2 || *result1 == *result3 || *result2 == *result3)
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta la vista\n");
    }

    return 0;
}

