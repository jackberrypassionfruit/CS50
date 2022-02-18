// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
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

// TODO_DONE: Choose number of buckets in hash table
// The biggest power of 26 that fits in an unsigned int, 4 bytes
const unsigned int N = 387420489;

// Hash table
node *table[N];

// Size counter for size()
unsigned int count = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO_DONE
    /*
    Hashes the first 6 letters of a word (at most) into an unsigned int
    26*6 is the number of buckets I will have in my hash table
    Any words that share the same first 6 letters will thus share a hash an collide
    Each of those will be in their own linked list together
    Wouldn't a trie be nice? Yes, but insanely too much memory, and wouldn't have the fun of hashing
    */

    int len = strlen(word);
    unsigned int hash_num = 0;

    if (len > 6)
    {
        len = 6;
    }

    for (int i = 0; i < len; i++)
    {
        int alph_index = tolower(word[i]) % 96;
        if (word[i] == '\'')
        {
            alph_index = 27;
        }
        hash_num += (alph_index * pow(26, i));
    }

    // printf("hash_num is: %u\n", hash_num);

    return hash_num;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO_DONE
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("dictionary couldn't load\n");
        return false;
    }

    char each_word[46];
    while (fscanf(dict, "%s", each_word) != EOF)
    {
        count++;
        // printf("word is: %s\n", each_word);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("couldn't create new node\n");
            fclose(dict);
            return false;
        }


        unsigned int hash_index = hash(each_word);

        // If no word at that node in the hash tree yet, create a head
        if (table[hash_index] == NULL)
        {
            table[hash_index] = n;
            strcpy((*table[hash_index]).word, each_word);
        }
        else
        {

            /* Steps to add new node to linked list in hash table
                1 - make newNode.next same as hashtable pntr
                2 - make newNode.word each_word
                3 - make hashtable pntr point to newNode
            */

           // 1
           (*n).next = table[hash_index];

           // 2
           strcpy((*n).word, each_word);

           // 3
           table[hash_index] = n;

           /* Currently wrong, and also dumb
                1 - assign current hashtable node.word to new node.word
                2 - make new node.next the same as current hashtable node.next
                3 - make current hashtable node.next point to new node
                4 - make current hashtable node.word the last each_word read from dictionary

            // 1
            strcpy((*n).word, (*table[hash_index]).word);
            // 2
            (*n).next = (*table[hash_index]).next;
            // 3
            (*table[hash_index]).next = n;
            // 4
            strcpy((*table[hash_index]).word, each_word);
            */
        }
    }

    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO_DONE
    unsigned int hash_index = hash(word);
    node *pntr = table[hash_index];

    while (pntr != NULL)
    {
        if (!(strcasecmp(word, (*pntr).word)))
            {
                return true;
            }
        pntr = (*pntr).next;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO_DONE
    // NVM, made a counter in load() now

    // unsigned int count = 0;
    // node *pntr;

    // for (int i = 0; i < N; i++)
    // {
    //     pntr = table[i].next;
    //     while ((*pntr).next != NULL)
    //     {
    //         count ++;
    //         pntr = (*pntr).next;
    //     }
    // }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *pntr = (*table[i]).next;
        node *tmp = pntr;
        while ((*pntr).next != NULL)
        {
            pntr = (*pntr).next;
            free(tmp);
            tmp = pntr;
        }
    }

    return false;
}
