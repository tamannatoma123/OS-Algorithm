#include <stdio.h>
#include <stdlib.h>

void FCFS(int requests[], int n, int head) {
    int total_head_movement = 0;
    printf("FCFS Disk Scheduling Order:\n");
    printf("%d -> ", head);

    for (int i = 0; i < n; i++) {
        printf("%d", requests[i]);
        if (i != n - 1) {
            printf(" -> ");
        }
        total_head_movement += abs(requests[i] - head);
        head = requests[i];  
    }
    printf("\nTotal Head Movement: %d\n", total_head_movement);
}
int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114}; 
    int n = sizeof(requests) / sizeof(requests[0]); 
    int head = 50; 

    FCFS(requests, n, head); 

    return 0;
}
