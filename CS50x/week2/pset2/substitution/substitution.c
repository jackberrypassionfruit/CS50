#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

/*
Pseudocode

(DONE) Pass 26-letter cipher key as single fn argument
(DONE) Check if key is a 26 letter string. If not:
    Remind what it should be
(CURRENT) If there's no argument at all, or too many:
    Remind what it should be
For each letter in key:
    Convert letter tolower()
Ask user for plain text, and store in variable
Print value of text to screen
Encrypt
    For each letter in Plaintext:
        Check if char is not a letter (ie. same toupper() and tolower())
        If yes: do no change
        If no:
            Check isupper(), and store result in boolean upper
            Convert letter tolower()
            Take modulo of letter and 97, to find its index in the alphabet (0-25)
            // You can do this bc the char is also an int if called as so
            Replace Plaintext letter with that index item of the key
            If upper is true:
                Convert letter toupper()
Print the newly converted ciphertext
Return the ciphertext
*/

int main(int argc, string argv[]) {
    string key = argv[1];
    int len = strlen(key);
    if (len != 26) {
        printf("Key must contain 26 characters.\n");
    }
    if (sizeof(argv[1] != sizeof('a') * 26 || )) {

    }
    for (int i = 0; i < len; i++) {
        key[i] = toupper(key[i]);
    }
    // printf("Key after changing to lowercase is: %s\n", key);
    return 0;
}