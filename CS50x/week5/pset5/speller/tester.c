#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *dict = fopen(argv[1], "w");
    if (dict == NULL)
    {
        printf("dictionary couldn't load\n");
        return 1;
    }

    char word[46];
    while (fscanf(dict, "%s", word) != EOF)
    {
        printf("word is: %s\n", word);
    }
    return 0;

}