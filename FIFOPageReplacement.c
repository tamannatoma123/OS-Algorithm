#include <stdio.h>

#define MAX_FRAMES 3
#define REF_STR_LEN 7

int main() {
    int ref_string[REF_STR_LEN] = {1, 3, 0, 3, 5, 6, 3};
    int frames[MAX_FRAMES];
    int front = 0, page_faults = 0;
    int i, j, found;

    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Page Replacement Sequence (FIFO):\n");

    for (i = 0; i < REF_STR_LEN; i++) {
        found = 0;

        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == ref_string[i]) {
                found = 1;  
                break;
            }
        }

        if (!found) {
            frames[front] = ref_string[i];      
            front = (front + 1) % MAX_FRAMES;   
            page_faults++;

            for (j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1)
                    printf(" - ");
                else
                    printf(" %d ", frames[j]);
            }
            printf(" <- Page fault\n");
        } else {
            
            for (j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1)
                    printf(" - ");
                else
                    printf(" %d ", frames[j]);
            }
            printf(" <- Page hit\n");
        }
    }

    printf("\nTotal Page Faults (Misses): %d\n", page_faults);
    return 0;
}
