#include <stdio.h>
#include <cs50.h>
#include <math.h>

// int getLengthOfLong();

int main(void) {
	long test = get_long("try me, user: ");
	// int len = getLengthOfLong(test);
    // long len = test%10;
	printf("%ld\n", test);
    return 1;
}

// int getLengthOfLong(loong) {
// int len = floor(log10(abs(loong))) + 1;

//     return len;
// }