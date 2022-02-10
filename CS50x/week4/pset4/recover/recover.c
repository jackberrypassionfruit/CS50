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

    FILE *output;
    uint8_t block[512];


    while (fread(&block, sizeof(uint8_t), 512, input))
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] >= 224 && block[3] <= 239)
        {

        }
    }
}