#include <stdio.h>
#include <cs50.h>

int main(void) {
    float letters = 65;
    float words = 14;
    float sent = 4;
    float L = letters / words;
    float S = sent / words;
    printf("Letters per word: %f\n", L);
    printf("Letters per sentences: %f\n", S);
}