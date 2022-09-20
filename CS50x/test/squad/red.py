import sys

card = open(sys.argv[1], "r")
lines = card.read()
hashes = 0
for line in lines:
    print(line, end="")
    for char in line:
        if char == "#":
            hashes += 1

card.close()

print(hashes)