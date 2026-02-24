#include <stdio.h>

int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20], pos;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority
    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time and Priority for Process %d: ", i+1);
        scanf("%d %d", &bt[i], &p[i]);
    }

    // Sorting according to priority (Lower number = Higher priority)
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if(p[j] < p[pos])
                pos = j;
        }

        // Swap burst time
        int temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap priority
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Waiting Time calculation
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    // Turnaround Time calculation
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",
               i+1, bt[i], p[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
