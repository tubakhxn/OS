#include <stdio.h>

int main() {
    int n; 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n];
    int burstTime[n];
    int completionTime[n];
    int turnaroundTime[n];
    int waitingTime[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }
        completionTime[i] = currentTime + burstTime[i];
        currentTime = completionTime[i];
    }

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    float avgTurnaroundTime = 0.0, avgWaitingTime = 0.0;
    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += turnaroundTime[i];
        avgWaitingTime += waitingTime[i];
    }
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);

    return 0;
}
