// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 308915776;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

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
        int ind = tolower(argv[1][i] % 96);
        hash_num += (ind * pow(26, i));
    }

    // printf("hash_num is: %u\n", hash_num);

    return hash_num;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO - Still has to actually take each of these words and put them into a hash table...after I implement the hash table function
    FILE *dict = fopen(argv[1], "r");
    if (dict == NULL)
    {
        printf("dictionary couldn't load\n");
        return 1;
    }

    char each_word[46];
    while (fscanf(dict, "%s", each_word) != EOF)
    {
        printf("word is: %s\n", each_word);
        node *n = malloc(sizeof(node))
        if (n == NULL)
        {
            printf("couldn't creat new node\n");
            return 2;
        }

        strcpy((*n).word, each_word);
        unsigned int hash_index = hash(each_word);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("no memory for new node\n");
            return 1;
        }
        (*n).word = each_word;
        (*n).next = table[hash_index].next;

    }



    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
