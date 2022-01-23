#include <stdio.h>
#include <cs50.h>
#include <math.h>

int getLengthOfLong();

int main(void) {
	double test = get_long("try me, user: ");
	int len = getLengthOfLong(test);
    // long len = test%10;
	printf("%i\n", len);
    return 1;
}

int getLengthOfLong(loong) {
	int len = log10(loong);

    return len;
}