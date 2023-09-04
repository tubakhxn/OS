//SJF using premitive approach in c program
#include <stdio.h>
#include<limits.h>
struct Process {
    int id;         
    int arrival;    
    int burst;      
};
void sjfScheduling(struct Process processes[], int n) {
    int totalTime = 0; 
    int waitingTime[n]; 
    for (int i = 0; i < n; i++) {
        waitingTime[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int shortest = -1; 
        int shortestBurst = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (processes[j].arrival <= totalTime && processes[j].burst < shortestBurst && processes[j].burst > 0) {
                shortest = j;
                shortestBurst = processes[j].burst;
            }
        }
        if (shortest == -1) {
            totalTime++;
        } else {
            waitingTime[shortest] = totalTime - processes[shortest].arrival;
            totalTime += processes[shortest].burst;
            processes[shortest].burst = 0;
        }
    }
    float totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        printf("Process %d: Waiting Time = %d\n", i + 1, waitingTime[i]);
    }
    float averageWaitingTime = totalWaitingTime / n;
    printf("Average Waiting Time = %.2f\n", averageWaitingTime);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }
    sjfScheduling(processes, n);

    return 0;
}
