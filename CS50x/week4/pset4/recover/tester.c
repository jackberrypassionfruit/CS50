#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        char name[7];
        sprintf(name, "%03i.jpg", i);
    }
}