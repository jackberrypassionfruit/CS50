#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

long getLLLength();

// Testing Conditionals in C

int main(void) {
    long i;
    i = get_long("Gimme a long: ");
    int len = getLLLength(i);
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

long getLLLength(i) {
    int len = 0;
    printf("num is: %ld\n", i);
    while (i > 0) {
        len++;
        i /= 10;
        // printf("num is: %lld\n", num);
    }
    return len;
}