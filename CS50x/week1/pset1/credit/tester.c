#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getLLLength();

// Testing Conditionals in C

int main(void) {
    long long i = get_long_long("Gimme a long: ");
    printf("i is: %lld\n", i);
    int len = getLLLength(i);
    // Converting Int to String
    printf("i is: %lld\n", i);


    char str[len];
    sprintf(str, "%lld", i);
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
    long long ref = num;
    printf("ref is: %lld\n", ref);
    while (ref > 0) {
        len++;
        ref /= 10;
        // printf("num is: %lld\n", num);
    }
    return len;
}