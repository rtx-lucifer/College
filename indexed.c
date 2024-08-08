#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50

void main() {
    int f[MAX_BLOCKS], index[MAX_BLOCKS], i, n, ind, count = 0, c, j, k;

    // Initialize all blocks as free
    for (i = 0; i < MAX_BLOCKS; i++) {
        f[i] = 0; // 0 indicates free, 1 indicates allocated
    }

    while (1) {
        printf("Enter the index block: ");
        scanf("%d", &ind);

        if (ind < 0 || ind >= MAX_BLOCKS) {
            printf("Invalid index block\n");
            continue;
        }

        if (f[ind] == 1) {
            printf("%d index is already allocated\n", ind);
        } else {
            f[ind] = 1; // Allocate the index block

            printf("Enter number of blocks needed for index %d: ", ind);
            scanf("%d", &n);

            if (n > MAX_BLOCKS - ind - 1) {
                printf("Insufficient free blocks\n");
                continue;
            }

            count = 0;
            for (i = ind + 1; i < ind + n + 1; i++) {
                if (f[i] == 0) {
                    count++;
                } else {
                    printf("Block %d is already allocated\n", i);
                }
            }

            if (count == n) {
                // All requested blocks are free, allocate them
                for (j = ind + 1; j < ind + n + 1; j++) {
                    f[j] = 1;
                }
                printf("Allocated\n");
                printf("File Indexed\n");
                for (k = ind + 1; k < ind + n + 1; k++) {
                    printf("%d -------- >%d : %d\n", ind, k, f[k]);
                }
            } else {
                printf("File in the index is already allocated \n");
                printf("Enter another file indexed: ");
                continue;
            }

            printf("Do you want to enter more files (Yes - 1/No - 0): ");
            scanf("%d", &c);
            if (c == 1) {
                continue;
            } else {
                exit(0);
            }
        }
    }
}
