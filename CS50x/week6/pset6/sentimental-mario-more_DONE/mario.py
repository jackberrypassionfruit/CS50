while True:
    height = int(input("Height of tower?: "))
    if height > 1 and height < 9:
        break

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1))
