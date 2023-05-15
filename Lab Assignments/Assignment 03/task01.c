//Mohammad Shafkat Hasan
//ID: 19101077
//Assigment 03
//Task01

#include <stdio.h>
#include <stdlib.h>

/*Given the list of processes, their CPU burst times, arrival times and implement SRTF scheduling algorithm, on the processes. Finally compute and print the completion Time(CT) for each process, and their average Turnaround Time(TAT), and average Waiting Time(WT).*/

#define MAX_PROCESSES 10

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes, i, j, time, min_remaining_time, min_remaining_index;

    // Read input
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    for (i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        printf("\nEnter details for process %d:\n", processes[i].pid);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        //scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // SRTF scheduling
    time = 0;
    while (1) {
        min_remaining_time = 99999;
        min_remaining_index = -1;

        // Find process with shortest remaining time
        for (i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time < min_remaining_time && processes[i].remaining_time > 0) {
                min_remaining_time = processes[i].remaining_time;
                min_remaining_index = i;
            }
        }

        if (min_remaining_index == -1) {
            // All processes have completed
            break;
        }

        // Execute process
        processes[min_remaining_index].remaining_time--;
        time++;

        // Update completion time, turnaround time, and waiting time for completed process
        if (processes[min_remaining_index].remaining_time == 0) {
            processes[min_remaining_index].completion_time = time;
            processes[min_remaining_index].turnaround_time = processes[min_remaining_index].completion_time - processes[min_remaining_index].arrival_time;
            processes[min_remaining_index].waiting_time = processes[min_remaining_index].turnaround_time - processes[min_remaining_index].burst_time;
        }
    }

    // Print output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    // Calculate average turnaround time and waiting time
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    for (i = 0; i < num_processes; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= num_processes;
    avg_waiting_time /= num_processes;
    printf("\nAverage turnaround time: %.2f\nAverage waiting time: %.2f\n", avg_turnaround_time, avg_waiting_time);

    return 0;
}

