#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[7];
    for (int i = 0; i < 5; i++)
    {
        sprintf(name, "%03i.jpg\n", i);
        printf("%s", name);
    }
}