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

    /* My problem is that only the first lines of the image are written.
    This is because I write to the jpegs only when I see the start of a new one.
    I stop writing, and leave off the rest this way.

    What I SHOULD do, is every time I see the start condition, close the output file I had been writing, iterate the filename, and open a newfile for the new jpeg.
    This is the file I will continue writing to until the new beginning.
    */

    sprintf(name, "000.jpg");
    FILE *output = fopen(name, "w");
    bool ready = false;

    // This next bit wouldn't work, reads date before I can use it
    // while (!(block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] >= 0xe0) && (block[3] <= 0xef)))
    //     {
    //         fread(&block, sizeof(uint8_t), 512, card);
    //     }

    while (fread(&block, sizeof(uint8_t), 512, card) == 512)
    {
        printf("blocks [1], [2], and [3] are: %x, %x,  %x, and %x\n", block[0], block[1], block[2], block[3]);
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] >= 0xe0) && (block[3] <= 0xef))
        {
            ready = true;
            i++;
            fclose(output);
            sprintf(name, "%03i.jpg", i);
            // printf("name is: %s\n", name);
            output = fopen(name,  "w");
        }
        fwrite(&block, sizeof(uint8_t), 512, output);
    }
    fclose(output);
    fclose(card);
    return 1;
}