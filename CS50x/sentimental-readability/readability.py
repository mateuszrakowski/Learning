from cs50 import get_string
import re

def main():
    text = get_string("Text: ")

    letterCounter = 0
    wordCounter = 1
    sentencesCounter = 0

    # Counting every letter, word and sentence in user text input
    for character in text:
        if character.isalpha():
            letterCounter += 1
        elif character.isspace():
            wordCounter += 1
        elif re.search(r'\!|\?|\.', character):
            sentencesCounter += 1

    L = letterCounter / wordCounter * 100
    S = sentencesCounter / wordCounter * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    # Printing results based on calculated index
    if index > 16:
        print("Grade: 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade: {}".format(round(index)))


if __name__ == "__main__":
    main()