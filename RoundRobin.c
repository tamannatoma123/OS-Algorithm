#include <stdio.h>

int main() {
    int n = 6;
    int timeQuantum = 5;
    int pid[] = {1, 2, 3, 4, 5, 6};
    int arrival[] = {0, 1, 2, 3, 4, 4};
    int burst[] =   {7, 4, 15, 11, 20, 9};
    int remaining[6];
    int completion[6] = {0};
    int turnaround[6] = {0};
    int waiting[6] = {0};
    int visited[6] = {0};

    for (int i = 0; i < n; i++) {
        remaining[i] = burst[i];
    }

    int queue[100], front = 0, rear = 0;
    int time = 0, completed = 0;

    for (int i = 0; i < n; i++) {
        if (arrival[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && arrival[i] <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];

        if (remaining[i] > timeQuantum) {
            time += timeQuantum;
            remaining[i] -= timeQuantum;
        } else {
            time += remaining[i];
            remaining[i] = 0;
            completion[i] = time;
            turnaround[i] = completion[i] - arrival[i];
            waiting[i] = turnaround[i] - burst[i];
            completed++;
        }

        
        for (int j = 0; j < n; j++) {
            if (!visited[j] && arrival[j] <= time && remaining[j] > 0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        if (remaining[i] > 0) {
            queue[rear++] = i;
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    return 0;
}
