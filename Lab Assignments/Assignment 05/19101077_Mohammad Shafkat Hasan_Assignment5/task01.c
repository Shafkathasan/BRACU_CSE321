//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 05
//Task01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if the system will face any deadlock in the future
int checkDeadlock(int n, int m, int alloc[n][m], int max[n][m], int avail[m])
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
            if (finish[i] == 0)
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                    else if (j == m - 1)
                    {
                        p = i;
                        break;
                    }

        // If no such process exist, then system is in safe state
        if (p == -1)
        {
            for (i = 0; i < n; i++)
                safeSeq[i] = 0;
            for (i = 0; i < n; i++)
                if (finish[i] == 0)
                    safeSeq[count++] = i;
            break;
        }

        // If a process exist, then mark it as finished
        finish[p] = 1;

        // Add the allocated resources of the current process to the available resources
        for (i = 0; i < m; i++)
            work[i] += alloc[p][i];
    }

    // If system is in safe state then return true, else return false
    if (count == n)
        return 1;
    else
        return 0;
}

// main function
int main()
{
    int n = 5, m = 4;

    int alloc[5][4] = {{0, 1, 0, 3},  // P0 // Allocation Matrix
                       {2, 0, 0, 0},  // P1
                       {3, 0, 2, 0},  // P2
                       {2, 1, 1, 5},  // P3
                       {0, 0, 2, 2}}; // P4;

    int max[5][4] = {{6, 4, 3, 4},  // P0 // MAX Matrix
                     {3, 2, 2, 1},  // P1
                     {9, 1, 2, 6},  // P2
                     {2, 2, 2, 8},  // P3
                     {4, 3, 3, 7}}; // P4

    int avail[4] = {3, 3, 2, 1}; // Available resources

    // Check if the system will face any deadlock in the future
    if (checkDeadlock(n, m, alloc, max, avail))
        printf("Safe!\n");
    else
        printf("Deadlock Ahead!\n");

    return 0;
}
