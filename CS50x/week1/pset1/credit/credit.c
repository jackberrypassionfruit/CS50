#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* Notes
Credit Card Identitifiers
	American Express
		15 Digit Numbers
		Starts w 34 or 37
	MasterCard
		16 Digit Numbers
		Starts w 51-55
	Visa
		16 or 13 Digit Numbers
		Starts w 4

Pseudocode

What We've Learned
- When calling a function, even if the functions expected a certain type of number, you still have to specifiy its type when you call that variable. It's dumb, but it'll assume it's an "int" if you don't
- I like c, but it's unforgiving

Weird Problems
- For some reason, not having an early printf statement for the global len variable cause the initial length test case to fail. Does printf change something about it?

*/



int getLongLength();
int luhnCheck();
int luhnStepOne();
int luhnStepTwo();
int luhnStepThree();

int len;

int main(void) {
	long cc = get_long("Number: ");
	// printf("cc is: %ld\n", cc);
	len = getLongLength(cc);
	char str[len];
	sprintf(str, "%ld", cc);
	// printf("str is: %s\n", str);
	printf("len is: %i\n", len);
	if ((str[0] == '3') && (len == 15)) {
		//Expect American Express
		if (luhnCheck(str)) {
			printf("AMERICAN EXPRESS\n");
			return 1;
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else if (str[0] == '5' && len == 16) {
		//Expect MasterCard
		if (luhnCheck(str)) {
			printf("MASTERCARD\n");
			return 1;
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else if (str[0] == '4' && (len == 13 || len == 16)) {
		//Expect Visa
		if (luhnCheck(str)) {
			printf("VISA\n");
			return 1;
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else {
		printf("This awful one\n");
		return 0;
	}
}

int getLongLength(long num) {
	return floor(log10(num)) + 1;
}

int luhnCheck(string str) {
	int L1 = luhnStepOne(str);
	int L2 = luhnStepTwo(str);
	int L3 = L1 + L2;
	return luhnStepThree(L3);
}

int luhnStepOne(string str) {
	int sum = 0;
	int adder;
	for (int i = len - 1; i >= 0; i -= 2) {
		adder = str[i - 1] - 48;
		sum += (adder * 2);
		printf("adder is: %i\n", adder);
		printf("Sum1 is: %i\n", sum);
	}
	return sum;
}

int luhnStepTwo(string str) {
	int sum = 0;
	for (int i = len; i >= 0; i -= 2) {
		int adder = str[i] - 48;
		sum += adder;
		// printf("Sum2 is: %i\n", sum);
	}
	// printf("Sum2 is: %i\n", sum);
	return sum;
}

int luhnStepThree(int L3) {
	long L3AsLong = (long) L3;
	int L3Len = getLongLength(L3AsLong);
	char L3Str[L3Len];
	sprintf(L3Str, "%i", L3);
	return (L3Str[L3Len -1] == 0);
}