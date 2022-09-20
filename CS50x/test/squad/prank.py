import sys

card1 = open(sys.argv[1], "r")
lines1 = [x.strip("\n") for x in card1.readlines()]
card2 = open(sys.argv[2], "r")
lines2 = [x.strip("\n") for x in card2.readlines()]
card3 = open(sys.argv[3], "r")
lines3 = [x.strip("\n") for x in card3.readlines()]
card4 = open(sys.argv[4], "r")
lines4 = [x.strip("\n") for x in card4.readlines()]
card5 = open(sys.argv[5], "r")
lines5 = [x.strip("\n") for x in card5.readlines()]
card6 = open(sys.argv[6], "r")
lines6 = [x.strip("\n") for x in card6.readlines()]

iter = 0
sign = ["", "", "", "", "", ""]

for line in lines1:
    sign[iter] += line
    iter += 1

iter = 0
for line in lines2:
    sign[iter] += " "
    sign[iter] += line
    iter += 1

iter = 0
for line in lines3:
    sign[iter] += " "
    sign[iter] += line
    iter += 1

iter = 0
for line in lines4:
    sign[iter] += " "
    sign[iter] += line
    iter += 1

iter = 0
for line in lines5:
    sign[iter] += " "
    sign[iter] += line
    iter += 1

iter = 0
for line in lines6:
    sign[iter] += " "
    sign[iter] += line
    iter += 1

for line in sign:
    print(line)


card1.close()
card2.close()
card3.close()
card4.close()
card5.close()
card6.close()