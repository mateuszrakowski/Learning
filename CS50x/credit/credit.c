#include <stdio.h>
#include <cs50.h>

int get_length(long cardnumber);

int main(void)
{
    long cardnumber;

    // Ask user to input a credit card number
    do
    {
        cardnumber = get_long("Credit card number: ");
    }
    while (cardnumber < 0);

    long n = cardnumber;

    // Used variables for calculate checksum
    int sum1 = 0;
    int sum2 = 0;

    int total = 0;

    int mod1;
    int mod2;

    int last_digit;
    int two_character_digit;

    // Check for credit card number length
    int length = get_length(cardnumber);

    // Calculate checksum
    for(int i = 0; i < length; i++)
    {
        mod1 = n % 10;
        n = n / 10;
        sum1 = mod1 + sum1;

        mod2 = n % 10;
        n = n / 10;

        mod2 = mod2 * 2;

        // Remember that data type int returns only integers(without decimal points), we can use this property to always return correct values using variables last_digit and two_character_digit, no matters if value is one-character digit or two-character digit
        last_digit = mod2 % 10;             // Examples: for value 12 returns 2 || For value 5 returns 5
        two_character_digit = mod2 / 10;    // Examples: for value 12 returns 1 || For value 5 returns 0
        sum2 = sum2 + last_digit + two_character_digit;
    }

    total = sum1 + sum2;

    // Checksum for credit cards and correct length
    if (total % 10 != 0 || length < 13 || length > 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Check first digits of the credit card
    long start = cardnumber;

    // Reduces the number to the first two digits using card number length - 2
    for (int j = 0; j < length-2; j++)
    {
        start /= 10;
    }

    // Checks the conditions to correctly adjust credit card
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Function to check the length of credit card, used for loops
int get_length(long cardnumber)
{
    int card_length = 1;

    while (cardnumber > 9)
    {
        card_length++;
        cardnumber /= 10;
    }

    return card_length;
}