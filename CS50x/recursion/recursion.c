#include <stdio.h>
#include <cs50.h>


int recursion(int n);

int main (void)
{
    int n = recursion(8);
    printf("%i\n", n);
}

int recursion(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + recursion(n/2);
    }
    else
    {
        return 1 + recursion(n*3+1);
    }
}