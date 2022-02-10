#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open card.raw file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
}