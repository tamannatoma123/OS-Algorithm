#include <stdio.h>
#include <stdlib.h>

void scan(int disk[], int size, int head) {
    int totalDistance = 0;
    int left[size], right[size];
    int leftCount = 0, rightCount = 0;

   
    for (int i = 0; i < size; i++) {
        if (disk[i] < head)
            left[leftCount++] = disk[i];
        else
            right[rightCount++] = disk[i];
    }

  
    for (int i = 0; i < leftCount - 1; i++) {
        for (int j = i + 1; j < leftCount; j++) {
            if (left[i] < left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    for (int i = 0; i < rightCount - 1; i++) {
        for (int j = i + 1; j < rightCount; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

   
    for (int i = 0; i < rightCount; i++) {
        totalDistance += abs(head - right[i]);
        head = right[i];
    }

    // Assume the head moves to end of disk (199) before reversing
    totalDistance += abs(head - 199);
    head = 199;

    // Then move to the left
    for (int i = 0; i < leftCount; i++) {
        totalDistance += abs(head - left[i]);
        head = left[i];
    }

    printf("Total distance: %d\n", totalDistance);
}

int main() {
    int disk[] = {14, 41, 53, 65, 67, 98, 122, 124, 183, 199};
    int size = sizeof(disk) / sizeof(disk[0]);
    int head = 53;

    scan(disk, size, head);

    return 0;
}