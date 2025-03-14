#include <stdio.h>

int main() {
    int n = 5;
    int pid[] = {1, 2, 3, 4, 5};
    int at[] = {2, 5, 1, 0, 4};
    int bt[] = {6, 2, 8, 3, 4};
    int ct[5], tat[5], wt[5];
    int temp, i, j;

    // Sorting (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap arrival times
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }


    int completed = 0, time = 0, min_bt, shortest;
    int visited[5] = {0};

    while (completed < n) {
        min_bt = 9999;
        shortest = -1;

        // Find the shortest job among the arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= time && visited[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    shortest = i;
                }
            }
        }


        if (shortest == -1) {
            time++;
            continue;
        }

        // Process execution
        time += bt[shortest];
        ct[shortest] = time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];
        visited[shortest] = 1;  // Mark as completed
        completed++;
    }

    // Print results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
