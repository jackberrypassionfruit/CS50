#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getIntLength();
int intToString();

// Testing Conditionals in C

int main(void) {
    int i = get_int("Gimme an int: ");
    int len = getIntLength(i);
    string str = intToString(i);
    if ((str[0] == 4) && (len == 3) || (len == 4)) {
        printf("fuck yeah");
    }
    else {
        printf("fuck noooo");
    }
}

// Converting Int to String

int intToString(i) {
    char str[len];
    sprintf(str, "%d", i);
}


int getIntLength(num) {
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return num;
}