#include <stdio.h>
struct Process {
    int id;             
    int arrivalTime;    
    int burstTime;     
    int turnaroundTime; 
    int waitingTime;    
};
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}
void sjfScheduling(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    processes[0].turnaroundTime = processes[0].burstTime;
    processes[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        processes[i].turnaroundTime = processes[i - 1].turnaroundTime + processes[i].burstTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    sjfScheduling(processes, n);

    float avgTurnaroundTime = 0.0;
    float avgWaitingTime = 0.0;

    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += processes[i].turnaroundTime;
        avgWaitingTime += processes[i].waitingTime;
    }

    avgTurnaroundTime /= n;
    avgWaitingTime /= n;
        printf("\n******************************* CHART *****************************************\n");
    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].turnaroundTime, processes[i].waitingTime);
    }
        printf("\n************************ AVG WAITING & TURNAROUND TIME IS GIVEN BELOW ********************\n");
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
