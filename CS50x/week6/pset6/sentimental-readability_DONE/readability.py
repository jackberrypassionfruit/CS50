def main():
    text = input("Text: ")

    letters = numb_helper(text, numbLetters)
    words = numb_helper(text, numbWords) + 1
    sentences = numb_helper(text, numbSentences)

    print(f"{letters} Letters\n {words} words\n {sentences} sentences")

    L = (letters / words) * 100
    S = (sentences / words) * 100

    level = round(0.0588 * L - 0.296 * S - 15.8)

    if level > 16:
        print("Grade 16+")
    elif level < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {level}")


def numbLetters(char):
    return char.isalpha()

def numbWords(char):
    return char == " "

def numbSentences(char):
    return char == "." or char == "?" or char == "!"

def numb_helper(str, func):
    num = 0
    for i in range(len(str)):
        if func(str[i]):
            num += 1
    return num


main()