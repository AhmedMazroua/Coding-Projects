// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>


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

//declare variables

unsigned int wrdcnt;
unsigned int hshval;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // declares variable set to hash "word" variable
    hshval = hash(word);
    node *cursor = table[hshval];


    // iterate through linked list
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);

    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *file = fopen(dictionary, "r");

    // open error result message
    if (file == NULL)
    {
        printf("file cannot be opened %s\n", dictionary);

        return false;
    }

    // declare char
    char word[LENGTH + 1];

    //scan dictionary for words and stop at EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        //request memory for node(s)
        node *n = malloc(sizeof(node));

        // if pointer is null returns false
        if (n == NULL)
        {
            return false;
        }

        //copy word into node
        strcpy(n->word, word);
        hshval = hash(word);
        n->next = table[hshval];
        table[hshval] = n;
        wrdcnt++;
    }
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // conditional
    if (wrdcnt > 0)
    {
        return wrdcnt;
    }
    return 0;


    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to the start of the linked list
        node *cursor = table[i];

        // If coursor is not NULL, free memory malloced
        while (cursor != NULL)
        {
            // Create temp node
            node *tmp = cursor;
            // Move cursor to next node
            cursor = cursor->next;
            // Free up temp node;
            free(tmp);
        }
    }
    return true;
}
