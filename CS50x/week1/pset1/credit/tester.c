#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getIntLength();

// Testing Conditionals in C

int main(void) {
    int i = get_int("Gimme an int: ");
    int len = getIntLength(i);
    // Converting Int to String

    char str[len];
    sprintf(str, "%i", i);
    printf("Int as a string: %s\n", str);

    if ((str[0] == 4) && ((len == 3) || (len == 4))) {
        printf("fuck yeah\n");
    }
    else {
        printf("fuck noooo\n");
    }
}

int getIntLength(num) {
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return num;
}