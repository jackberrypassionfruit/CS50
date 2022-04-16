import sys

card1 = open(sys.argv[1], "r")
lines1 = [x.strip() for x in card1.readlines()]

card2 = open(sys.argv[2], "r")
lines2 = [x.strip() for x in card2.readlines()]

for line1, line2 in zip(lines1, lines2):
    print(line1, end=" ")
    print(line2, end="\n")


card1.close()
card2.close()