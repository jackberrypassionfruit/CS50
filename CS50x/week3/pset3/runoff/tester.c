#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int x = 4;
    int y = 93;
    printf("x / y = %d\n", (float) y / (float) x > 20.0);
}