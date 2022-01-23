#include <stdio.h>
#include <cs50.h>

int getLengthOfLong();

int main(void) {
	long test = get_long("try me, user: ");
	int len = getLengthOfLong(test);
    // long len = test%10;
	printf("%i\n", len);
}

int getLengthOfLong(loong) {
	int len = 0;
	while (loong > 10) {
		len++;
		loong = loong / 10;
	}
    return len;
}