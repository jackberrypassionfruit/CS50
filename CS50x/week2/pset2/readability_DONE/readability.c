#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

float numberOfLetters(string text);
float numberOfWords(string text);
float numberOfSentences(string text);

int totLen;

int main(void)
{
    string text = get_string("Text: ");
    totLen = strlen(text);
    float letters = numberOfLetters(text);
    float words = numberOfWords(text);
    float sent = numberOfSentences(text);
    float L = (letters / words) * 100;
    // printf("Letters per 100 words: %f\n", L);
    float S = (sent / words) * 100;
    // printf("Sentences per 100 words: %f\n", S);
    float level = roundf(0.0588 * L - 0.296 * S - 15.8);
    int ans = level;
    if (ans > 16)
    {
        printf("Grade 16+\n");
    }
    else if (ans < 1)
    {
        printf ("Before Grade 1\n");
    }
    else
    {
        printf("Grade Level: %i\n", ans);
    }
    return 0;
}

// DONE
float numberOfLetters(string text)
{
    float num = 0;
    char letter;
    for (int i = 0; i < totLen; i++)
    {
        letter = text[i];
        // printf("Letter: %c\n", letter);
        if (toupper(letter) != tolower(letter))
        {
            num += 1;
        }
    }
    // printf("Number of Letters: %f\n", num);
    return num;
}

// DONE
float numberOfWords(string text)
{
    //Starting from 1 to account for the fact that there won't be a space after the last word
    float num = 1;
    char letter;
    for (int i = 0; i < totLen; i++)
    {
        letter = text[i];
        if (letter == ' ')
        {
            num += 1;
        }
    }
    // printf("Number of words is: %f\n", num);
    return num;
}

// DONE
float numberOfSentences(string text)
{
    float num = 0;
    char letter;
    for (int i = 0; i < totLen; i++)
    {
        letter = text[i];
        if (letter == '.' || letter == '?' || letter == '!')
        {
            num += 1;
        }
    }
    // printf("Number of sentences is: %f\n", num);
    return num;
}