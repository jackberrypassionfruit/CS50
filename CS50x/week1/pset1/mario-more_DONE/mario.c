#include <stdio.h>
#include <cs50.h>

int drawEmpties();
int drawBlocks();

int main(void) {
    int height = 0;
    do {
        height = get_int("Please, dear Yahweh please, give me a number: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++) {
        drawEmpties(i, height);
    drawBlocks(i, height);
        printf("  ");
        drawBlocks(i, height);
        printf("\n");
    }
    return 1;
}

// Prints each individual Line of blocks
int drawEmpties(int lvl, int height) {
    for (int i = 0; i < (height - lvl); i++) {
        printf(" ");
    }
    return 1;
}

int drawBlocks(int lvl, int height) {
    for (int i = 0; i < lvl; i++) {
        printf("#");
    }
    return 1;
}

/* Pseudocode
ask for HEIGHT from user
for i in rows:
    print empty spaces for the amount of height minus the level
    print as many hashes as the level
    print 2 empty spaces
    print just the hashes
*/