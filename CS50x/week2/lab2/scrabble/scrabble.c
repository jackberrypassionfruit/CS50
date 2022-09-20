#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    /* Pseudocode
    Make sure the word is in all lowercase
    Store the index of each letter in alph
    Add the point value of each letter to pnts based on the key above

    */

    int len = strlen(word);
    int pnts = 0;
    int alph;
    // word = word.tolower();
    for (int i = 0; i < len; i++)
    {
        if (toupper(word[i]) != tolower(word[i]))
        {
            word[i] = tolower(word[i]);
            // printf("word[i] is: %c\n", word[i]);
            alph = word[i] - 97;
            // printf("alph is: %i\n", alph);
            pnts += POINTS[alph];
            // printf("pnts is: %i\n", pnts);
        }
    }
    return pnts;
}

