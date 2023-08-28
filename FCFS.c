#include <stdio.h>

float calculateAverageWaitingTime(int n, int burstTime[], int waitingTime[], int compileTime, int turnaroundTime, int arivalTime) {
    float totalWaitingTime = 0;

for (int i=0; i<n; i++){
    waitingTime[i] = compileTime - arivalTime;
    totalWaitingTime += waitingTime[i];
    compileTime += burstTime[i];
}

return totalWaitingTime/n;

}

int main(){

    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    int burstTime[n], waitingTime[n], compileTime[n], turnaroundTime[n];
    int arivalTime = 0;

    for (int i=0; i<n; i++){
                printf("Enter the burst time of process %d:", i+1);
                scanf("%d", &burstTime[i]);
                compileTime[i] = burstTime[i] + arivalTime;
                arivalTime += burstTime[i];

    }

    float averageWaitingTime = calculateAverageWaitingTime(n, burstTime, waitingTime, compileTime[n-1], turnaroundTime[n-1], arivalTime);

    printf("Average waiting time: %f", averageWaitingTime);

    return 0;
}
