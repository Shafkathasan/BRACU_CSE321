//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 03
//Task03

#include <stdio.h>

/*Given the list of processes, their CPU burst times, arrival times, priority and implement priority scheduling algorithm, on the processes. Finally compute and print the completion Time(CT) for each process, and their Turnaround Time(TAT), and Waiting Time(WT).*/

// priority scheduling algorithm
int main()
{
    int at[20], wt[20], tat[20], bt[20], pri[20], ct[20];
    int number, temp[20], t, count = 0, small;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of Processes: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        printf("\nEnter Process P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        printf("Priority: ");
        scanf("%d", &pri[i]);
    }

    pri[9] = 999999;

    for (t = 0; count != number; t++)
    {
        small = 9;
        for (int i = 0; i < number; i++)
        {
            if (pri[small] > pri[i] && at[i] <= t && bt[i] > 0)
            {
                small = i;
            }
        }

        bt[small] = bt[small] - 1;

        if (bt[small] == 0)
        {

            count++;
            tat[small] = t + 1 - at[small] - temp[small]; //Turnaround Time(TAT)
            wt[small] = t + 1 - at[small]; //Waiting Time(WT)

            ct[small] = t + 1; //Completion Time(CT)
        }
    }
	
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1,at[i],temp[i], ct[i], wt[i], tat[i]);
    }

    return 0;
}
