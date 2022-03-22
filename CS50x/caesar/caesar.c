#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Functions prototype
bool only_digits(string plaintext);
char rotate(char characters, int key);

// Main checks if the only 1 argument is given by user, otherwise prints information about correct usage
int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converts string to int data type
    int key = atoi(argv[1]);

    // Gets a prompt from user and checks the length of the string
    string plaintext = get_string("Plaintext:  ");
    int length = strlen(plaintext);

    printf("Ciphertext: ");

    // Loop iterates through string and prints every character next to each other using key value given by user and rotate function
    for (int i = 0; i < length; i++)
    {
        char ciphertext = rotate(plaintext[i], key);
        printf("%c", ciphertext);
    }

    printf("\n");
}

// Function checks if prompt given by user is integer
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

// Function corresponding to check lowercase/uppercase condition for given character, rotates the character by given key on values from 0-25 using remainder.
// The character will always be from 0 to 25 value, which we assign in this function to letters a-z (case insensitive).
char rotate(char characters, int key)
{
    if (isupper(characters))
    {
        characters -= 'A';
        characters = (characters + key) % 26;

        return characters + 'A';
    }

    else if (islower(characters))
    {
        characters -= 'a';
        characters = (characters + key) % 26;

        return characters + 'a';
    }

    else
    {
        return characters;
    }

}