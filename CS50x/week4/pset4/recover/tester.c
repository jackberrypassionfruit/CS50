#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *name = malloc(sizeof(char) * 8);
    sprintf(name, "005.jpg");
    printf("%s\n", name);
    sprintf(name, "006.jpg");
    printf("%s\n", name);
}