#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getIntLength();
int longToString();

// Testing Conditionals in C

int main(void) {
    int i = get_int("Gimme an int: ");
    int len = getIntLength(i);
    string str = longToString(i);
    if ((str[0] == 4) && (len == 3) || (len == 4)) {
        printf("fuck yeah");
    }
    else {
        printf("fuck noooo");
    }
}

// Converting Long to String

int longToString(loong) {
    char str[len];
    sprintf(str, "%ld", loong);
}


int getIntLength(num) {
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return num;
}