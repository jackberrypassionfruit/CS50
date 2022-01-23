#include <stdio.h>
#include <cs50.h>
#include <math.h>

double getLengthOfLong();

int main(void) {
	double test = get_long("try me, user: ");
	double len = getLengthOfLong(test);
    // long len = test%10;
	printf("%f\n", len);
    return 1;
}

double getLengthOfLong(loong) {
	double len = log10(loong);

    return len;
}