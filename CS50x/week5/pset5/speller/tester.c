#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *dict = fopen(argv[1], "r");
    char word[46];
    while (fscanf(dict, "%s", word) != EOF)
    {
        if (!(strcmp(argv[2], word)))
        {
            printf("word is in dictionary\n");
            return true;
        }
    }
    printf("not a word, shitfuck\n");



    return 0;

}