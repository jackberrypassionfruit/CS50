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

int luhnCheck();
int luhnStepOne();
int luhnStepTwo();
int luhnStepThree();

int main(void) {
	long cc = get_long("Number: ");
	if (cc[0] == 3) {
		//Expect American Express
		if luhnCheck(cc) {
			printf("AMERICAN EXPRESS");
			return 1
		}
		else {
			printf("INVALID");
			return 0;
		}
	}
	else if (cc[0] == 5) {
		//Expect MasterCard
		if luhnCheck(cc) {
			printf("MASTERCARD");
			return 1
		}
		else {
			printf("INVALID");
			return 0;
		}
	}
	else if (cc[0] == 4) {
		//Expect Visa
		if luhnCheck(cc) {
			printf("VISA");
			return 1
		}
		else {
			printf("INVALID");
			return 0;
		}
	}
	else {
		printf("INVALID");
		return 0;
	}
}

int luhnCheck(cc) {
	int L1 = luhnStepOne(cc);
	int L2 = luhnStepTwo(L1);
	return luhnStepThree(L2);
}

