#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int length = strlen(word);
    int score = 0;

    for (int i = 0; i < length; i++)
    {
        // Transform the characters to lowercase to standarize 
        if (word[i] >= 65 && word[i] <= 90)
        {
            word[i] += 32;
        }


        if (word[i] == 97 || word[i] == 101 || word[i] == 105 || word[i] == 108 || word[i] == 110 || word[i] == 111 || word[i] == 114 || word[i] == 115 || word[i] == 116 || word[i] == 117)
        {
            score += 1;
        }
        else if (word[i] == 100 || word[i] == 103)
        {
            score += 2;
        }
        else if (word[i] == 98 || word[i] == 99 || word[i] == 109 || word[i] == 112)
        {
            score += 3;
        }
        else if (word[i] == 102 || word[i] == 104 || word[i] == 118 || word[i] == 119 || word[i] == 121)
        {
            score += 4;
        }
        else if (word[i] == 107)
        {
            score += 5;
        }
        else if (word[i] == 106 || word[i] == 120)
        {
            score += 8;
        }
        else if (word[i] == 113 || word[i] == 122)
        {
            score += 10;
        }
        else
        {
            score += 0;
        }
    }

    return score;
}
