#include <stdio.h>
#include <cs50.h>

int drawEmpties();
int drawBlock();

int main(void) {
	int height = get_int("Please, dear Yahweh please, give me a number: ");
	for (int i = 1; i <= height; i++) {
		drawEmpties(i, height);
		drawBlock(i, height);
		printf("  ");
		drawBlocks(i, height);
		drawEmpties(i, height);
		printf("\n");
	})
}

// Prints each individual Line of blocks
int drawEmpties(lvl, height) {
	for (int i = 0; i < (height - lvl); i++) {
		printf(' ');
	}
}

int drawBlocks(lvl, height) {
	for (int i = 0; i < lvl; i++) {
		printf('#');
}

/* Pseudocode
ask for HEIGHT from user
for i in rows:
	print empty spaces for the amount of height minus the level
	print as many hashes as the level
	print 2 empty spaces
	# do the last two things, but in reverse order
*/