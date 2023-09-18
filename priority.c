//WAP to implement the CPU scheduling Algo for Priority.
#include <stdio.h>

void findWaitingTime(int processes[], int n, int burst_time[], int waiting_time[], int priority[]) {
    waiting_time[0] = 0; 

    for (int i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (int j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
    }
}

void findTurnaroundTime(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
}

void findAverageTime(int processes[], int n, int burst_time[], int priority[]) {
    int waiting_time[n], turnaround_time[n];

    findWaitingTime(processes, n, burst_time, waiting_time, priority);
    findTurnaroundTime(processes, n, burst_time, waiting_time, turnaround_time);

    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], priority[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i]);
        printf("Enter the Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter the Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    findAverageTime(processes, n, burst_time, priority);

    return 0;
}
