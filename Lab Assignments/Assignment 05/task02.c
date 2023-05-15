//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 04
//Task02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to generate safe sequence of process execution
void safeSeq(int n, int m, int alloc[n][m], int max[n][m], int avail[m])
{
    // Declare variables
    int i, j, k;
    int need[n][m];
    int work[m];
    int finish[n];
    int safeSeq[n];
    int count = 0;

    // Initialize finish array
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Initialize work array
    for (i = 0; i < m; i++)
        work[i] = avail[i];

    // Calculate Need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Mark all processes as unfinished
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Find a safe sequence
    while (1)
    {
        // Find a process which is not finished and whose needs can be satisfied with current work array
        int p = -1;
        for (i = 0; i < n; i++)
        {
            int flag = 0;
            for (j = 0; j < m; j++)
                if (need[i][j] > work[j])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0 && finish[i] == 0)
            {
                p = i;
                break;
            }
        }

        // If there is no such process, then we are done
        if (p == -1)
        {
            printf("Safe sequence is: \n");
            for (i = 0; i < n; i++)
            {
                if (i == n - 1)
                    printf("P%d", safeSeq[i]);
                else
                    printf("P%d -> ", safeSeq[i]);
            }
            printf("\n");
            break;
        }

        // Add this process in safe sequence
        safeSeq[count++] = p;

        // Mark this process as finished
        finish[p] = 1;

        // Add the allocated resources of the current process to the available resources
        for (i = 0; i < m; i++)
            work[i] += alloc[p][i];
    }
}

// main function
int main()
{
    int n = 6;                        // Number of processes
    int m = 4;                        // Number of resources
    int alloc[6][4] = {{0, 1, 0, 3},  // P0 // Allocation Matrix
                       {2, 0, 0, 3},  // P1
                       {3, 0, 2, 0},  // P2
                       {2, 1, 1, 5},  // P3
                       {0, 0, 2, 2},  // P4
                       {1, 2, 3, 1}}; // P5
    int max[6][4] = {{6, 4, 3, 4},    // P0 // MAX Matrix
                     {3, 2, 2, 4},    // P1
                     {9, 1, 2, 6},    // P2
                     {2, 2, 2, 8},    // P3
                     {4, 3, 3, 7},    // P4
                     {6, 2, 6, 5}};   // P5
    int avail[4] = {2, 2, 2, 1};      // Available resource

    safeSeq(n, m, alloc, max, avail);

    return 0;
}
