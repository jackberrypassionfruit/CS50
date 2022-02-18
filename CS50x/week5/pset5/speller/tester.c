#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    typedef struct node
    {
        char word[46 + 1];
        struct node *next;
    }

    node;

    node *n = malloc(sizeof(node));

    if ((*n).next == NULL)
    {
        printf("true\n");
    }
    free(n);
    return 1;
}