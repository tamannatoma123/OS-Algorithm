#include <stdio.h>

int main() {
    int arr1[] = {2, 0, 4}; // Arrival times
    int arr2[] = {5, 3, 4}; // Burst times
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Sort arrival times and adjust burst times accordingly
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;

                temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    // Swap first two elements of burst time array
    int temp = arr2[0];
    arr2[0] = arr2[1];
    arr2[1] = temp;

    int completion[n], turnaround[n], waiting[n];

    // Calculate Completion Time (CT)
    completion[0] = arr1[0] + arr2[0];
    for (int i = 1; i < n; i++) {
        if (completion[i - 1] < arr1[i]) {
            completion[i] = arr1[i] + arr2[i];
        } else {
            completion[i] = completion[i - 1] + arr2[i];
        }
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arr1[i];
        waiting[i] = turnaround[i] - arr2[i];
    }

    // Print results
    printf("Sorted Arrival Times: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Swapped Burst Times: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Completion Time: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", completion[i]);
    }
    printf("\n");

    printf("Turnaround Time: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", turnaround[i]);
    }
    printf("\n");

    printf("Waiting Time: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", waiting[i]);
    }
    printf("\n");

    return 0;
}
