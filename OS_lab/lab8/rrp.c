// Round Robin scheduling with Priority algorithm
#include <stdio.h>

// calculate waiting time
void fwt(int processes[], int n, int bt[], int wt[], int quantum, int priority[]) {
    int rem_bt[n];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i]; 
        wt[i] = 0; 
    }
    int t = 0; 
    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; 
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break; 
    }
}

// calculate turn around time
void ftat(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; 
    }
}

void fps(int processes[], int n, int bt[], int quantum, int priority[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Sort processes by priority (higher priority first, lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    fwt(processes, n, bt, wt, quantum, priority);

    ftat(processes, n, bt, wt, tat);

    printf("Processes   Burst Time   Priority   Waiting Time   Turnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n], priority[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter the priority for process %d (Lower number = higher priority): ", i + 1);
        scanf("%d", &priority[i]);
        processes[i] = i + 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    fps(processes, n, bt, quantum, priority);

    return 0;
}