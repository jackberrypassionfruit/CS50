#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int len = strlen(argv[1]);
    unsigned int hash_num = 0;

    if (len > 6)
    {
        len = 6;
    }

    for (int i = 0; i < len; i++)
    {
        int alph_index = tolower(argv[1][i]) % 96;
        hash_num += (alph_index * pow(26, i));
    }

    hash_num -= 1;
    printf("hash_num is: %u\n", hash_num);

    return hash_num;
}