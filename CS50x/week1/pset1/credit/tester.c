#include <stdio.h>
#include <cs50.h>
#include <math.h>

long getLengthOfLong();

int main(void) {
	long test = get_long("try me, user: ");
	long len = getLengthOfLong(test);
    // long len = test%10;
	printf("%ld\n", len);
    return 1;
}

long getLengthOfLong(loong) {
	long len = log10(loong);

    return len;
}