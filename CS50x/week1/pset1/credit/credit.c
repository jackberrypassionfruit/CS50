#include <stdio.h>
#include <cs50.h>

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

*/

int getLongLength();
int longToString();
int luhnCheck();
int luhnStepOne();
int luhnStepTwo();
int luhnStepThree();

int main(void) {
	long cc = get_long("Number: ");
	int len = getLongLength(cc);
	string str = longToString(cc, len);
	printf("str is: %s\n", str);
	if ((cc[0] == 3) && (len == 15)) {
		//Expect American Express
		if luhnCheck(cc) {
			printf("AMERICAN EXPRESS\n");
			return 1
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else if (cc[0] == 5 && len == 16) {
		//Expect MasterCard
		if luhnCheck(cc) {
			printf("MASTERCARD\n");
			return 1
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else if (cc[0] == 4) {
		//Expect Visa
		if luhnCheck(cc) {
			printf("VISA\n");
			return 1
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else {
		printf("INVALID\n");
		return 0;
	}
}

int getLongLength(num) {
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return num;
}

string longToString(loong, len) {
	char str[len];
	sprintf(str, "%ld", loong);
	return str;
}

int luhnCheck(cc) {
	int L1 = luhnStepOne(cc);
	int L2 = luhnStepTwo(L1);
	return luhnStepThree(L2);
}

int luhnStepOne(cc) {

}

int luhnStepTwo(L1) {

}

int luhnStepTwo(L2) {

}