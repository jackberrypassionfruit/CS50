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

Weird Problems
- For some reason, not having an early printf statement for the global len variable cause the initial length test case to fail. Does printf change something about it?

*/

int getLongLength();
int luhnCheck();
int luhnStepOne();
int luhnStepTwo();

int len;

int main(void)
{
    long cc = get_long("Number: ");
    // printf("cc is: %ld\n", cc);
    len = getLongLength(cc);
    char str[len];
    sprintf(str, "%ld", cc);
    // printf("str is: %s\n", str);
    printf("");
    if ((str[0] == '3' && (str[1] == '4' || str[1] == '7')) && (len == 15))
    {
        //Expect American Express
        if (luhnCheck(str))
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (str[0] == '5' && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5') && len == 16)
    {
        //Expect MasterCard
        if (luhnCheck(str))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (str[0] == '4' && (len == 13 || len == 16))
    {
        //Expect Visa
        if (luhnCheck(str))
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int getLongLength(long num)
{
    return floor(log10(num)) + 1;
}

int luhnCheck(string str)
{
    int L1 = luhnStepOne(str);
    int L2 = luhnStepTwo(str);
    int L3 = L1 + L2;
    return (L3 % 10 == 0);
}

int luhnStepOne(string str)
{
    int sum = 0;
    int adder;
    for (int i = len - 1; i >= 1; i -= 2)
    {
        //Set adder to every other digit in the credit card, doubled, starting from the 2nd last
        adder = 2 * (str[i - 1] - 48);
        //Add the digits within the number "adder" to sum, BUT NOT ADDER ITSELF
        if (adder >= 10)
        {
            sum += 1 + (adder - 10);
        }
        else
        {
            sum += adder;
        }
    }
    return sum;
}

int luhnStepTwo(string str)
{
    int sum = 0;
    for (int i = len; i > 0; i -= 2)
    {
        int adder = str[i - 1] - 48;
        sum += adder;
    }
    return sum;
}