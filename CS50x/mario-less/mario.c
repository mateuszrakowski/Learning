#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Put a number between 1 and 8 to build a pyramid: ");
    }
    while (n < 1 || n > 8);


    for (int i = 0; i < n; i++)
    {

        // Builds a blank space on pyramid depends on the row (stage of the main loop)
        for (int j = 0; j < (n-1)-i; j++)
        {
            printf(" ");
        }

        // Builds a brick on pyramid depends on the row (stage of the main loop)
        for (int k = 0; k < i+1; k++)
        {
            printf("#");
        }

        // Adds a new line at the end of every iteration to make rows
        printf("\n");
    }
}