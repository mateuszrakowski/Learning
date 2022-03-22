#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Checks if given number is positive, if fails asks again till correct value is given. Then returns the value of cents.
    int cents;

    do
    {
        cents = get_int("How many cents the customer is owed? ");
    }
    while (cents < 1);

    return cents;
}

int calculate_quarters(int cents)
{
    // Returns a number of quarters that contains the given value of cents.
    int quarters = cents/25;
    return quarters;
}

int calculate_dimes(int cents)
{
    // Returns a number of dimes that contains the given value of cents (operates on value potentially reduced by previous function call inside main(void) to properly sum number of coins).
    int dimes = cents/10;
    return dimes;
}

int calculate_nickels(int cents)
{
    // Returns a number of nickels that contains the given value of cents (operates on value potentially reduced by previous function call inside main(void) to properly sum number of coins).
    int nickels = cents/5;
    return nickels;
}

int calculate_pennies(int cents)
{
    // Returns a number of pennies that contains the given value of cents (operates on value potentially reduced by previous function call inside main(void) to properly sum number of coins).
    int pennies = cents/1;
    return pennies;
}
