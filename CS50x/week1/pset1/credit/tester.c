#include <stdio.h>
#include <cs50.h>

int getLengthOfLong();

int main(void) {
	long test = get_long("try me, user: ");
	int len = getLengthOfLong(test);
    // long len = test%100;
	printf("%i\n", len);
}

int getLengthOfLong(loong) {
	int len = 0;
	while (loong > 1) {
		len++;
		len = loong%10;
	}
    return len;
}