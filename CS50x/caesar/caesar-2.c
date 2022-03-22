#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string plaintext);
char rotate(char characters, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("Plaintext:  ");
    int length = strlen(plaintext);

    printf("Ciphertext: ");

    for (int i = 0; i < length; i++)
    {
        char ciphertext = rotate(plaintext[i], key);
        printf("%c", ciphertext);
    }

    printf("\n");
}

bool only_digits(string plaintext)
{
    int length = strlen(plaintext);
    int checkdigits = 0;

    for (int i = 0; i < length; i++)
    {
        if (isdigit(plaintext[i]))
        {
            checkdigits++;
        }
    }

    if (checkdigits == length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char rotate(char characters, int key)
{
    if (isupper(characters))
    {
        characters = characters - 'A';

        while (key > 0 && characters < 26)
        {
            characters++;
            key--;

            if (characters == 25)
            {
                characters = characters % 25;
                key -= 1;
            }
            else if (key == 0)
            {
                return characters + 'A';
            }
        }
    }

    else if (islower(characters))
    {
        characters = characters - 'a';

        while (key > 0 && characters < 26)
        {
            characters++;
            key--;

            if (characters == 25)
            {
                characters = characters % 25;
                key -= 1;
            }
            else if (key == 0)
            {
                return characters + 'a';
            }
        }

        if (key == 0)
        {
            return characters + 'a';
        }
    }

    else
    {
        return characters;
    }

    return 0;
}