#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    // Ask user to put a correct number (at least once), if failed ask again till success
    do
    {
        n = get_int("Put a number between 1 and 8 to build a pyramids: ");
    }
    while (n < 1 || n > 8);

    // Main loop for making rows
    for (int i = 0; i < n; i++)
    {

        // Making a progressive space to push our bricks(#) to the right, starting from input (n - 1) - to create a place for first brick and so on making a next one space (-i) for next row every iteration
        for (int h = 0; h < (n-1)-i; h++)
        {
            printf(" ");
        }

        // Loop that creates bricks of left wall of pyramid
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }

        // Loop responsible to always make the same gap between walls
        for (int k = 0; k < 2; k++)
        {
            printf(" ");
        }

        // Loop that creates bricks of right wall of pyramid
        for (int l = 0; l < i+1; l++)
        {
            printf("#");
        }

        // Creating a newline (next row)
        printf("\n");
    }
}