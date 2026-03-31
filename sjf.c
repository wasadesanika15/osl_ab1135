#include <stdio.h>

#define MAX_PROCESSES 10

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int remaining_bt[MAX_PROCESSES];
    int complete = 0, current_time = 0;
    int finish_time, shortest;
    int min_bt;

    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
        wt[i] = 0;
    }

    while (complete != n) {
        shortest = -1;
        min_bt = 999;

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        remaining_bt[shortest]--;
        current_time++;

        if (remaining_bt[shortest] == 0) {
            complete++;
            finish_time = current_time;
            wt[shortest] = finish_time - bt[shortest];
        }
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTimes(int processes[], int n, int bt[]) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",
               processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {6, 8, 7, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, n, burst_time);
    return 0;
}
