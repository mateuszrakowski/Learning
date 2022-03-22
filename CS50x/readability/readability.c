#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Getting prompt from the user
    string text = get_string("Text: ");

    // Counting the numbers using the functions
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Counting the numbers L and S for Coleman-Liau index and changing the integers to floats
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Grade results based on the index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

// Counting the letters by using iteration through string(text) and 'is alphabetical' condition
int count_letters(string text)
{
    int length = strlen(text);
    int letters = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// Counting the words by using the iteration and 'is whitespace' condition
int count_words(string text)
{
    int length = strlen(text);
    int count_spaces = 0;

    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            count_spaces++;
        }
    }

    return count_spaces + 1;
}

// Counting the sentences using iteration and condition that counts !?. (Basic function not including dots present inside sentences)
int count_sentences(string text)
{
    int length = strlen(text);
    int count_special = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count_special++;
        }
    }

    return count_special;
}