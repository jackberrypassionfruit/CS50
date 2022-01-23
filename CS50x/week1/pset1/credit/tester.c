#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getIntLength();

// Testing Conditionals in C

int main(void) {
    long i = get_long("Gimme a long: ");
    int len = getIntLength(i);
    printf("len is: %i\n", len);
    // Converting Int to String

    char str[len];
    sprintf(str, "%ld", i);
    printf("str[0] is: %c\n", str[0]);

    if (str[0] == '4' && (len == 3 || len == 4)) {
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
        printf("num is: %i\n", num);
    }
    return len;
}