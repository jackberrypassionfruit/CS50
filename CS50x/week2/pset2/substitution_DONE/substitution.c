#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

/*
Pseudocode

(DONE) Pass 26-letter cipher key as single fn argument
(DONE) Check if key is a 26 letter string. If not:
    Remind what it should be
(DONE) If there's no argument at all, or too many:
    Remind what it should be
(DONE) For each letter in key:
    Convert letter toupper()
(DONE) Ask user for plain text, and store in variable

Encrypt
    For each letter in Plaintext:
        Check if char is not a letter (ie. same toupper() and tolower())
        If yes: do no change
        If no:
            Check isupper(), and store result in boolean up
            Convert letter tolower()
            Take modulo of letter and 97, to find its index in the alphabet (0-25)
            // You can do this bc the char is also an int if called as so
            Replace Plaintext letter with that index item of the key
            If upper is true:
                Convert letter toupper()
Print the newly converted ciphertext
Return the ciphertext
*/

string cypher(string ptext);
string key;

int main(int argc, string argv[])
{
    key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }
    string ptext = get_string("plaintext: ");
    string ctext = cypher(ptext);
    printf("ciphertext: %s\n", ctext);
    // printf("Key after changing to UPPERCASE is: %s\n", key);
    return 0;
}

string cypher(string ptext)
{
    int len = strlen(ptext);
    int up;
    char c;
    for (int i = 0; i < len; i++)
    {
        c = ptext[i];
        if (toupper(c) != tolower(c))
        {
            up = isupper(c);
            c = tolower(c);
            // printf("up is: %i\n", up);
            c %= 97;
            ptext[i] = key[c];
            if (!up)
            {
                ptext[i] = tolower(ptext[i]);
            }
            // printf("ptext[i] is: %c\n\n", ptext[i]);
        }
    }
    return ptext;
}
