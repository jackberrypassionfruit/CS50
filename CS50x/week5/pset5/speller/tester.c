#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *dict = fopen(argv[1]);
    if (dict == NULL)
    {
        printf("dictionary couldn't load\n");
        return 1;
    }

    FILE *word = fopen("word.txt", "w");
    while (fscanf(dict, "%s", word) == EOF)
    return 0;

}