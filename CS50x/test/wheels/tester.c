#include <stdio.h>
#include <string.h>


int main()
{
    char c[10] = "apfelsaft";

    for (int i = 0; i < strlen(c); i++)
    {
        *(c + i) = (char) *(c + i) + 1;
    }
    printf("%s\n", c);
}