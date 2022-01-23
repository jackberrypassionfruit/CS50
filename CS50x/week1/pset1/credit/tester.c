#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void) {
    long num = get_long("gimme a long: ");
    int len = 0;
    printf("Num after input is: %ld\n", num);
    while (num > 0) {
        len++;
        num /= 10;
        printf("Num after each division is: %ld\n", num);
    }
    printf("len is: %i\n", len);
    return 1;
}