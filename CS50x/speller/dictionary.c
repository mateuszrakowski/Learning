// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Counting the number of words in dictionary
int wordCounter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Checks if the word is present in bucket according to hash code
    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }

        // Moves to the next node inside bucket
        cursor = cursor -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Takes string and returns an integer
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Temporary array to store strings
    char words[LENGTH + 1];

    // Open dictionary file and check if is it valid
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // While there are strings inside a text file, create nodes, assign to them words
    // and insert them to the beginning of the bucket
    while (fscanf(dict, "%s", words) != EOF)
    {
        node *nextWord = malloc(sizeof(node));
        if (nextWord == NULL)
        {
            return false;
        }

        // Copy the string from words array to node
        strcpy(nextWord -> word, words);

        // Get hash value to choose correct bucket
        int index = hash(words);

        // Insert node to the beginning of the bucket
        // First assign pointer of the new node to 1st node inside bucket
        // Then set head pointer to the new node
        nextWord -> next = table[index];
        table[index] = nextWord;

        // Counts how many words are inside the dictionary
        wordCounter++;
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return the counted value
    return wordCounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Two pointers moving from node to node and freeing one per move
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor -> next;
            free(tmp);
            tmp = cursor;
        }
    }

    return true;
}
