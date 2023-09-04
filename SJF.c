//SJF using non-premitive approach in c program
#include <stdio.h>

struct Process {
    int id;       
    int burstTime; 
};

void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortByBurstTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].burstTime < processes[minIndex].burstTime) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            swap(&processes[i], &processes[minIndex]);
        }
    }
}

void SJF(struct Process processes[], int n) {
    sortByBurstTime(processes, n);
    printf("Process Execution Order: ");
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].id);
        currentTime += processes[i].burstTime;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }

    SJF(processes, n);

    return 0;
}





