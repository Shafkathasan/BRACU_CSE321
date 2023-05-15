//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 03
//Task02

#include <stdio.h>

#define MAX_PROCESSES 100

/*Given the list of processes, their CPU burst times, time quantum and implement round robin scheduling algorithm, on the processes. Finally compute and print the completion Time(CT) for each process, and their Turnaround Time(TAT), and Waiting Time(WT).*/

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
};

int main() {
    int n, quantum, time = 0;
    struct Process processes[MAX_PROCESSES];
    int completed[MAX_PROCESSES] = {0};
    int ct[MAX_PROCESSES] = {0};
    int tat[MAX_PROCESSES] = {0};
    int wt[MAX_PROCESSES] = {0};

    // Input the number of processes and the time quantum
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Input the burst times of each process
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Run the round robin scheduling algorithm
    while (1) {
        int all_completed = 1;
        for (int i = 0; i < n; i++) {
            if (completed[i] == 0) {
                all_completed = 0;
                if (processes[i].remaining_time > quantum) {
                    processes[i].remaining_time -= quantum;
                    time += quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed[i] = 1;
                    ct[i] = time;
                    tat[i] = ct[i];
                    wt[i] = tat[i] - processes[i].burst_time;
                }
            }
        }
        if (all_completed) {
            break;
        }
    }

    // Output the completion time, turnaround time, and waiting time for each process
    printf("\n");
    printf("Process\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].burst_time, ct[i], tat[i], wt[i]);
    }

    return 0;
}

