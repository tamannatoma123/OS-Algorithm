#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {0, 14, 41, 53, 65, 67, 98, 122, 124, 183, 199};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53, disk_size = 200, total = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }

    
    int index = 0;
    while (index < n && requests[index] < head)
        index++;

    for (int i = index; i < n; i++) {
        total += abs(head - requests[i]);
        head = requests[i];
    }

    if (head != disk_size - 1) {
        total += abs(head - (disk_size - 1));
        total += disk_size - 1; // jump to 0
        head = 0;
    }

   
    for (int i = 0; i < index; i++) {
        total += abs(head - requests[i]);
        head = requests[i];
    }

    printf("Total distance = %d\n", total);
    return 0;
}