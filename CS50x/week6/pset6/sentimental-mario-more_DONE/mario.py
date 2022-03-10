while True:
    height = int(input("Height of tower?: "))
    if height > 2 and height < 8:
        break

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="  ")
    print("#" * (i + 1))
