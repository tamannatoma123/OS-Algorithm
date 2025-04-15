#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void elevatorDiskScheduling(int requests[], int n, int head, char direction[], int diskSize) {
    int seekSequence[100];
    int seekCount = 0;
    int index = 0;

    int left[100], right[100];
    int leftCount = 0, rightCount = 0;

    sort(requests, n);

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftCount++] = requests[i];
        else
            right[rightCount++] = requests[i];
    }

    if (strcmp(direction, "up") == 0) {
        for (int i = 0; i < rightCount; i++)
            seekSequence[index++] = right[i];

        for (int i = leftCount - 1; i >= 0; i--)
            seekSequence[index++] = left[i];
    } else {
        for (int i = leftCount - 1; i >= 0; i--)
            seekSequence[index++] = left[i];

        for (int i = 0; i < rightCount; i++)
            seekSequence[index++] = right[i];
    }

    int current = head;
    for (int i = 0; i < index; i++) {
        seekCount += abs(seekSequence[i] - current);
        current = seekSequence[i];
    }

    printf("Seek Sequence: ");
    for (int i = 0; i < index; i++) {
        printf("%d", seekSequence[i]);
        if (i < index - 1)
            printf(" -> ");
    }
    printf("\nTotal Seek Operations: %d\n", seekCount);
}

int main() {
    int requestSequence[] = {137, 240, 179, 75, 118, 29, 15, 51};
    int n = sizeof(requestSequence) / sizeof(requestSequence[0]);
    int head = 55;

    elevatorDiskScheduling(requestSequence, n, head, "up", 300);

    return 0;
}
