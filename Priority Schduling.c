#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;          
    int priority;     
    int at;          
    int bt;          
    int ct;          
    int tat;         
    int wt;          
    int remaining_bt; 
} Process;

void preemptive_priority_scheduling(Process p[], int n) {
    int completed = 0, time = 0, highest_priority, idx;

    while (completed < n) {
        highest_priority = -1;
        idx = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining_bt > 0) {
                if (p[i].priority > highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) { 
            time++;
            continue;
        }

        p[idx].remaining_bt--;
        time++;

        if (p[idx].remaining_bt == 0) {
            completed++;
            p[idx].ct = time;  
            p[idx].tat = p[idx].ct - p[idx].at; 
            p[idx].wt = p[idx].tat - p[idx].bt; 
        }
    }
}

void print_process_table(Process p[], int n) {
    printf("Process\tPriority\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].priority, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main() {
    Process p[] = {
        {1, 10, 0, 5, 0, 0, 0, 5},
        {2, 20, 1, 4, 0, 0, 0, 4},
        {3, 30, 2, 2, 0, 0, 0, 2},
        {4, 40, 4, 1, 0, 0, 0, 1}
    };

    int n = sizeof(p) / sizeof(p[0]);

    preemptive_priority_scheduling(p, n);
    print_process_table(p, n);

    return 0;
}
