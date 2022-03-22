#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool is_letter(string key);
bool is_unique(string key);
char rotate(char letter, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (is_letter(argv[1]) == false)
    {
        printf("Key contains invalid characters.\n");
        return 1;
    }

    if (is_unique(argv[1]) == false)
    {
        printf("Key shouldn't contain duplicate characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    printf("ciphertext: ");

    for (int i = 0; i < length; i++)
    {
        char ciphertext = rotate(plaintext[i], argv[1]);
        printf("%c", ciphertext);
    }

    printf("\n");
}

bool is_letter(string key)
{
    int length = strlen(key);

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    return true;
}

bool is_unique(string key)
{
   for (int i = 0, j = strlen(arg_letters); i < j; i++)
   {
      for (int k = i+1; k < j; k++)
      {
         if (arg_letters[i] == arg_letters[k])
         {
            return false;
         }

      }
   }
   return true;
}

char rotate(char character, string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }

    if (isupper(character))
    {
        character -= 'A';

        character = key[(int) character];

        return character;
    }
    else if (islower(character))
    {
        character -= 'a';

        character = key[(int) character];

        return tolower(character);
    }

    return character;
}