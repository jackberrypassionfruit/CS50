#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void) {
    long num = get_long("gimme a long: ");
    printf("Long after input is: %ld\n", num);
    return 1;
}