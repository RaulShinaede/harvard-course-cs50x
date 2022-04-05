#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("What's the tower height (1 at 8): ");

    while ((!height) || (height < 1 || height > 8))
    {
        if (height < 1)
        {
            printf("\nThe height must be greater than 0.\n\n");
        }
        else if (height > 8)
        {
            printf("\nThe height must be less than 9.\n\n");
        }

        height = get_int("What's the tower height (1 at 8): ");
    }

    for (int row = 1; row <= height; row++)
    {

        int blockQty = row;
        int blankQty = (height - row);

        // Creates the blanks so that the tower faces the other side

        for (int blank = 1; blank <= blankQty; blank++)
        {
            printf(" ");
        }

        // Creates first side of the tower

        for (int block = 1; block <= blockQty; block++)
        {
            printf("#");
        }

        printf("  ");

        // Creates second side of the tower

        for (int block = 1; block <= blockQty; block++)
        {
            printf("#");
        }

        printf("\n");
    }
}