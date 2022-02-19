
""" Notes
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
"""

from math import *

def main():
    cc = input("Enter a credit card number, please: ")
    nums = len(cc)
    
    # print("cc[0] is: ", cc[0])
    # print("nums is: ", nums)

    if luhn(cc) != 0:
        print("INVALID")

    elif nums == 15 and (cc[0:1] == "34" or cc[0:1] == "37"):
        print("AMEX")

    elif nums == 16 and cc[0] == "5" and (cc[1] == "1" or cc[1] == "2" or cc[1] == "3" or cc[1] == "4" or cc[1] == "5"):
        print("MASTERCARD")
    
    elif (nums == 16 or nums == 13) and cc[0] == "4":
        print("VISA")

    else:
        print("INVALID")
    
    



def luhn(cc):
    step1 = 0 # DONE
    for i in range(-2, (-1 * len(cc)) - 1, -2):
        digit = 2 * int(str(cc)[i])
        if digit >= 10:
            step1 += 1 + (digit - 10)
        else:
            step1 += digit

    step2 = 0
    for i in range(-1, (-1 * len(cc)) - 1, -2):
        digit = int(str(cc)[i])
        step2 += digit

    step3 = (step1 + step2) % 10
    # print("luhn is: ", step3)
    return step3

main()