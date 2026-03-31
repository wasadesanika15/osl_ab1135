#include <stdio.h>

int main()
{
    int i, n;
    printf("Enter number of Processes: \n");
    scanf("%d", &n);

    int at[n], bt[n], rem_bt[n];
    int ct[n], tat[n], wt[n];

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time for process %d: \n", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for process %d: \n", i + 1);
        scanf("%d", &bt[i]);

        rem_bt[i] = bt[i];
        ct[i] = tat[i] = wt[i] = 0;
    }

    int tq;
    printf("Enter Time Quantum:\n");
    scanf("%d", &tq);

    int time = 0;
    int completed = 0;

    while (completed < n) {
        int ready = 0;

        for (i = 0; i < n; i++) {

            if (at[i] <= time && rem_bt[i] > 0) {

                ready = 1;

                if (rem_bt[i] <= tq) {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
                else {
                    time += tq;
                    rem_bt[i] -= tq;
                }
            }
        }

        if (!ready) {
            time++;  // If no process is ready, move time forward
        }
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcesses\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
