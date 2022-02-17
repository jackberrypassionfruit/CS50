#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        hash_num += ((int) word[i]) * pow(26, i + 1);
    }

    return hash_num;
}