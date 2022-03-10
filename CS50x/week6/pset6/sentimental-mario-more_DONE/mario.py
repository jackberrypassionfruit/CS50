import cs50

while True:
    height = cs50.get_int("Height: ")
    if height > 1 and height < 9:
        break

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1))
