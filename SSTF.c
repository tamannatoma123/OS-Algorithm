#include <stdio.h>
#include <stdlib.h>

#define SIZE 8 

void SSTF(int requests[], int head, int size) {
    int visited[size]; 
    int distance, minDistance, index;
    int totalSeekCount = 0;

    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    printf("SSTF Disk Scheduling:\n");
    printf("Sequence of Head Movements: ");

   
    for (int i = 0; i < size; i++) {
        minDistance = 999999; 

        for (int j = 0; j < size; j++) {
            if (!visited[j]) { 
                distance = abs(head - requests[j]);

                if (distance < minDistance) {
                    minDistance = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;

        totalSeekCount += minDistance;

        head = requests[index];

      
        printf("%d ", head);
    }

    printf("\nTotal Seek Count: %d\n", totalSeekCount);
}

int main() {
    int requests[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int size = SIZE;

    SSTF(requests, head, size);

    return 0;
}
