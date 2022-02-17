#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
        hash_num += ((int) argv[1][i]) * pow(26, i + 1);
    }

    printf("hash_num is: %lu\n", hash_num);

    return 1;
}