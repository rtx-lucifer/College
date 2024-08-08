#include <stdio.h>
#include <conio.h>

void main() {
    int f[50], i, st, len, j, c, k, count = 0;

    // Clear the screen (specific to some compilers)
    clrscr();
    
    // Initialize all blocks as free (0)
    for(i = 0; i < 50; i++)
        f[i] = 0;
    
    printf("Files Allocated are : \n");
    
    x: count = 0;
    
    // Taking input for starting block and length of file
    printf("Enter starting block and length of files: ");
    scanf("%d%d", &st, &len);
    
    // Check if the required blocks are free
    for(k = st; k < (st + len); k++) {
        if(f[k] == 0)
            count++;
    }
    
    if(len == count) {
        // Allocate the blocks
        for(j = st; j < (st + len); j++) {
            if(f[j] == 0) {
                f[j] = 1;
                printf("%d\t%d\n", j, f[j]);
            }
        }
        if(j == (st + len))
            printf("The file is allocated to disk\n");
    } else {
        printf("The file is not allocated\n");
    }
    
    // Ask if the user wants to enter more files
    printf("Do you want to enter more files (Yes - 1 / No - 0): ");
    scanf("%d", &c);
    
    if(c == 1)
        goto x;
    else
        printf("File allocation process completed.\n");
    
    getch();  // To hold the screen (specific to some compilers)
}
