#include <stdio.h>

struct Process {
    int no, arrival, burst, remaining, completion, turnAround, waiting, response;
};

void roundRobin(struct Process proc[], int n, int quantum) {
    int queue[n], front = 0, rear = 0, time = 0, completed = 0;
    int inQueue[n], firstResponse[n];

    for (int i = 0; i < n; i++) {
        inQueue[i] = 0;
        firstResponse[i] = 0;
    }

    queue[rear++] = 0;
    inQueue[0] = 1;

    while (completed < n) {
        int i = queue[front++];

        if (!firstResponse[i]) {
            proc[i].response = time - proc[i].arrival;
            firstResponse[i] = 1;
        }

        if (proc[i].remaining > quantum) {
            time += quantum;
            proc[i].remaining -= quantum;
        } else {
            time += proc[i].remaining;
            proc[i].remaining = 0;
            proc[i].completion = time;
            proc[i].turnAround = proc[i].completion - proc[i].arrival;
            proc[i].waiting = proc[i].turnAround - proc[i].burst;
            completed++;
        }

        for (int j = 0; j < n; j++) {
            if (proc[j].arrival <= time && proc[j].remaining > 0 && !inQueue[j]) {
                queue[rear++] = j;
                inQueue[j] = 1;
            }
        }

        if (proc[i].remaining > 0) {
            queue[rear++] = i;
        }
    }
}

void printProcesses(struct Process proc[], int n) {
    printf("No\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].no, proc[i].arrival, proc[i].burst,
               proc[i].completion, proc[i].turnAround, proc[i].waiting, proc[i].response);
    }
}

int main() {
    struct Process proc[] = {{1, 0, 5, 5, 0, 0, 0, 0},
                             {2, 1, 4, 4, 0, 0, 0, 0},
                             {3, 2, 2, 2, 0, 0, 0, 0},
                             {4, 4, 1, 1, 0, 0, 0, 0}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int quantum = 2;

    roundRobin(proc, n, quantum);
    printProcesses(proc, n);
    return 0;
}
