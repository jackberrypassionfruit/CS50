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
    char *name = malloc(sizeof(char) * 8);
    if (name == NULL)
    {
        printf("name was NULL\n");
        return 1;
    }

    /*
    Every time I see the start condition, close the output file I had been writing, iterate the filename, and open a newFile for the new jpeg.
    This is the file I will continue writing to until the new file beginning.
    */

    FILE *output = fopen(name, "w");
    int ready = 1;

    while (fread(&block, sizeof(uint8_t), 512, card) == 512)
    {
        // printf("blocks [1], [2], and [3] are: %x, %x,  %x, and %x\n", block[0], block[1], block[2], block[3]);

        // Before ready is true (ie. 0) waits for jpeg header. Then writes to output below
        if (!((block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] >= 0xe0) && (block[3] <= 0xef))) && ready == 1)
        {
            continue;
        }

        // Does same jpeg header check but now with
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] >= 0xe0) && (block[3] <= 0xef))
        {
            ready = 0;
            fclose(output);
            sprintf(name, "%03i.jpg", i);
            output = fopen(name,  "w");
            i++;
        }
        fwrite(&block, sizeof(uint8_t), 512, output);
    }
    free(name);
    fclose(output);
    fclose(card);
    return 0;
}