// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
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
        printf("word is: %s\n", word);
        node *n = malloc(sizeof(node))
        if (n == NULL)
        {
            printf("couldn't creat new node\n");
            return 2;
        }

        strcpy((*n).name, &each_word);
        unsigned int index = hash(each_word);

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
