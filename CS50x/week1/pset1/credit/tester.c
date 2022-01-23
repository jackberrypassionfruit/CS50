#include <stdio.h>
#include <cs50.h>

// int getLengthOfLong();

int main(void) {
	double test = get_long("try me, user: ");
	// int len = getLengthOfLong(test);
    int tester;
    tester = test;
    int f = 4;
    int len = log(f, 10);
	printf("%i\n", len);
}

// int getLengthOfLong(loong) {
// 	int len = 0;
// 	while (loong > 0) {
// 		len++;
// 		loong /= 10;
// 	}
//     return len;
// }