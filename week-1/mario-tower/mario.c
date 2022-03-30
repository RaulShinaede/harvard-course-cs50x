#include <stdio.h>

int main(void) {

    int height = 0;

    while (height < 1 || height > 8) {
        printf("What's the tower height (1 at 8): ");
        scanf("%d", &height);

        if (height < 1) printf("\nThe height must be greater than 0.\n\n");
        if (height > 8) printf("\nThe height must be less than 9.\n\n"); 
    }

    for(int row = 1; row <= height; row++) {

        int blockQty = row;
        int blankQty = (height - row);

        for (int blank = 1; blank <= blankQty; blank++) printf(" ");
        for (int block = 1; block <= blockQty; block++) printf("#"); 
        
        printf(" ");

        for (int block = 1; block <= blockQty; block++) printf("#"); 
        
        printf("\n");
    }
}