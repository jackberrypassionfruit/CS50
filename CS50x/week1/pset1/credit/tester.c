#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void) {
    long num = get_long("gimme a long: ");
    int len = 0;
    printf("Long after input is: %ld\n", num);
    while (num > 0) {
        len++;
        num /= 10;
    }
    return 1;
}