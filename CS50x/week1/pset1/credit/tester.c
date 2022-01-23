#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getLengthOfLong();

int main(void) {
	long cc = get_long("try me, user: ");
    printf("Loong is %d\n", cc);
    int len = getLengthOfLong(cc);
	printf("%i\n", len);
    return 1;
}

int getLengthOfLong(loong) {
    int len = 0;
    while (loong > 0) {
        len++;
        loong = loong / 10;
        printf("Loong is %d\n", loong);
        printf("Len is %i\n", len);
    }
    return len;
}