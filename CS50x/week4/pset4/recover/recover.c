#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open card.raw file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t block[512];


    int i = 0;
    char *name = malloc(sizeof(char) * 7);

    // Hopfully block is rest with new info every time this next fread function is called
    while (fread(&block, 512, 1, card) == 512)
    {
        printf("blocks [1], [2], and [3] are: %x, %x,  %x, and %x\n", block[0], block[1], block[2], block[3]);
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] >= 0xe0) && (block[3] <= 0xef))
        {
            sprintf(name, "%03i.jpg", i);
            printf("name is: %s\n", name);
            FILE *output = fopen(name,  "w");
            fwrite(&block, 512, 1, output);
            fclose(output);
            i++;
        }
    }
    fclose(card);
    return 1;
}