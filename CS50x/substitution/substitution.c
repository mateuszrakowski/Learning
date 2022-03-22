#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Function prototype
bool is_letter(string key);
bool is_unique(string key);
char rotate(char letter, string key);

// Main asks for command-line arguments
int main(int argc, string argv[])
{

    // Condition to check if one key is given
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checks if key has exactly 26 letters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Checks if key has only letters
    if (is_letter(argv[1]) == false)
    {
        printf("Key contains invalid characters.\n");
        return 1;
    }

    // Checks if key contains only unique (not duplicate) letters
    if (is_unique(argv[1]) == false)
    {
        printf("Key shouldn't contain duplicate characters.\n");
        return 1;
    }

    // Take user prompt as a string
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    printf("ciphertext: ");

    // Prints characters next to each other after cipher
    for (int i = 0; i < length; i++)
    {
        char ciphertext = rotate(plaintext[i], argv[1]);
        printf("%c", ciphertext);
    }

    printf("\n");
}

// Function used to check if key contains only letters
bool is_letter(string key)
{
    int length = strlen(key);

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i])) // Iterate through every key character to check if it contains non-letter characters if (!isalpha(key[i]) == true)
        {
            return false;
        }
    }

    return true;
}

// Function used to check if key contains only unique (not duplicate) letters
bool is_unique(string key)
{
    int length = strlen(key);
    int count[26] = {0};

    for (int i = 0; i < length; i++)
    {
        count[toupper(key[i]) - 'A']++; // Unifies key characters to uppercase and changes their value to 0-25 (depends on character) and then sets value 1 to every index
    }

    for (int j = 0; j < length; j++)
    {
        if (count[j] != 1) // If any character was present more than one time, previous loop added more than 1 to the value of specific index (value of that index will be 2 or more)
        {
            return false;
        }
    }

    return true;
}

// Function that by using given key changes the plaintext to ciphertext
char rotate(char character, string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]); // Unifies key to uppercase to let modify it in next conditions
    }

    if (isupper(character))
    {
        character -= 'A'; // Sets the ASCII value of the character from 0 to 25 (0 = A, 1 = B and so on)

        character = key[(int) character]; // Using alphabetical numeration sequence we can set the character (single plaintext letter) to analogue position in key sequence. For example character(F) will be key[5] (because F=70 and 70-65=5) which means fifth position in our key sequence
        return character;
    }
    else if (islower(character))
    {
        character -= 'a'; // Sets the ASCII value of the character from 0 to 25 (0 = a, 1 = b and so on)

        character = key[(int) character]; // Using alphabetical numeration sequence we can set the character (single plaintext letter) to analogue position in key sequence

        return tolower(character);
    }

    return character;
}