#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getLengthOfLong();

int main(void) {
	long test = get_long("try me, user: ");
    int len = getLengthOfLong(test);
	printf("%i\n", len);
    return 1;
}

int getLengthOfLong(loong) {
    int len = 0;
    while (loong > 0) {
        len++;
        loong /= 10;
    }
    return len;
}