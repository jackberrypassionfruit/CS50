#include <stdio.h>
#include <cs50.h>

int main(void) {
    long big = get_long("Gimmme a big ass number: ");
    // while (big > 1) {
    big = big / 10;
    big = big / 10;

    printf("%lu\n", big);
}