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

What We've Learned
- When calling a function, even if the functions expected a certain type of number, you still have to specifiy its type when you call that variable. It's dumb, but it'll assume it's an "int" if you don't
- I like c, but it's unforgiving

*/



int getLongLength();
int luhnCheck();
int luhnStepOne();
int luhnStepTwo();
int luhnStepThree();

int main(void) {
	long cc = get_long("Number: ");
	// printf("cc is: %ld\n", cc);
	int len = getLongLength(cc);
	// printf("len is: %i\n", len);
	char str[len];
	sprintf(str, "%ld", cc);
	// printf("str is: %s\n", str);
	if ((str[0] == '3') && (len == 15)) {
		//Expect American Express
		if (luhnCheck(cc)) {
			printf("AMERICAN EXPRESS\n");
			return 1;
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else if (str[0] == 5 && len == 16) {
		//Expect MasterCard
		if (luhnCheck(cc)) {
			printf("MASTERCARD\n");
			return 1;
		}
		else {
			printf("INVALID\n");
			return 0;
		}
	}
	else if (str[0] == 4) {
		//Expect Visa
		if (luhnCheck(cc)) {
			printf("VISA\n");
			return 1;
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

int getLongLength(long num) {
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

int luhnCheck(cc) {
	int L1 = luhnStepOne(cc);
	int L2 = luhnStepTwo(L1);
	return luhnStepThree(L2);
}

int luhnStepOne(cc) {
return 1;
}

int luhnStepTwo(L1) {
return 1;
}

int luhnStepThree(L2) {
return 1;
}