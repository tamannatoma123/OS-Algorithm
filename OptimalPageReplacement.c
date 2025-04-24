#include <stdio.h>

#define REF_STR_LEN 14
#define MAX_FRAMES 4

int predict(int ref_string[], int frames[], int index, int n) {
    int res = -1, farthest = index;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == ref_string[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) 
            return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int ref_string[REF_STR_LEN] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int frames[MAX_FRAMES];
    int page_faults = 0, hits = 0;
    int i, j, k;
    int is_full = 0;

    for (i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;

    printf("Page Replacement Sequence (Optimal):\n");

    for (i = 0; i < REF_STR_LEN; i++) {
        int found = 0;

        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == ref_string[i]) {
                hits++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (is_full < MAX_FRAMES) {
                frames[is_full++] = ref_string[i];
            } else {
                int replace_index = predict(ref_string, frames, i + 1, REF_STR_LEN);
                frames[replace_index] = ref_string[i];
            }
            page_faults++;

            for (k = 0; k < MAX_FRAMES; k++) {
                if (frames[k] == -1)
                    printf(" - ");
                else
                    printf(" %d ", frames[k]);
            }
            printf(" <- Page fault\n");
        } else {
            for (k = 0; k < MAX_FRAMES; k++) {
                if (frames[k] == -1)
                    printf(" - ");
                else
                    printf(" %d ", frames[k]);
            }
            printf(" <- Page hit\n");
        }
    }

    printf("\nTotal Page Faults (Misses): %d\n", page_faults);
    printf("Total Page Hits: %d\n", hits);

    return 0;
}
