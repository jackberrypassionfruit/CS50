#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "dictionary.c"

int main(int argc, char *argv[])
{
    int hash_index = hash("'");
    printf("%i\n", hash_index);
    return 1;
}