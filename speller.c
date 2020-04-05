// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int totalWords = 0;
int hashNumber;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *checker = table[hash(word)];
    //first word in list
    if (strcasecmp(checker -> word, word) == 0)
    {
        return true;
    }
    //subsequent words in list
    while (checker -> next != NULL)
    {
        checker = checker -> next;
        if (strcasecmp(checker -> word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
// Djb2 hash function by Dan Bernstein
unsigned int hash(const char *word)
{
    int n = (int) tolower(word[0]) - 97;
    return n;
    
    //int hash = 5381;
    //int c;
    //while ((c = *word++))
    //{
    //hash = ((hash << 5) + hash) + c; /* hash * 33 +c */
    //}
    //return hash%N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        return false;
    }
    char *dictWord = malloc(LENGTH);
    //Read strings from file one at a time
    while (fscanf(file, "%s", dictWord) != EOF)
    {
         //Create a new node for each word
         node *n = malloc(sizeof(node));
         if (n == NULL)
         {
            return false;
         }
         //copy word in to node using strcpy
         strcpy(n -> word, dictWord);
         totalWords++;

        //Hash word to a obtain a hash value
        hashNumber = hash(dictWord);
        //Insert node into hash table at that location
        // set next on the new node to point at start of list (currently stored in table[hashNumber]).
        n -> next = table[hashNumber];
        // Now n points to list I can safely set the hash table pointing to n without oprhaning list.
        table[hashNumber] = n;
    }
    free(dictWord);
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return totalWords;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node* deleter;
    node* temp;
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        deleter = table[i];
        temp = deleter;
        while (deleter != NULL)
        {
        deleter = deleter -> next;
        free(temp);
        temp = deleter;
        }
    }
    free(deleter);
    return true;
}
