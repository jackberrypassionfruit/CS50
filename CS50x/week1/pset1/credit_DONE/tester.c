#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getLLength();
int getLenWMath();

// Testing Conditionals in C

int main(void) {
    long i = get_long("Gimme a long: ");
    // printf("i is: %ld\n", i);
    int len = getLenWMath(i);
    printf("len is: %i\n", len);

    // Converting Long Long to String
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

// Crappy Iterative version
int getLLength(long num) {
    int len = 0;
    printf("num is: %ld\n", num);
    while (num > 0) {
        len++;
        num /= 10;
        printf("num is: %ld\n", num);
    }
    return len;
}

// Better Math Version
int getLenWMath(long num) {return floor(log10(num)) + 1;}