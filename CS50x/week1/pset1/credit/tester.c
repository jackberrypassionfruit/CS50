#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getLLLength();

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

int getLLLength(num) {
    int len = 0;
    printf("num is: %ld\n", num);
    while (num > 0) {
        len++;
        num /= 10;
        // printf("num is: %lld\n", num);
    }
    return len;
}