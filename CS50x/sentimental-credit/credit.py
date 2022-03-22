from cs50 import get_string
import re

def main():
    # Get user input
    creditCard = get_string("Number: ")

    # Check the length of the input
    valid = re.search(r'\d{15}|\d{13}|\d{16}', creditCard)

    # If input isn't a credit card number length
    if valid == None:
        print("INVALID")
        return

    # Checks if input is correct credit card number
    checkSum = luhn_algorithm(creditCard)

    if checkSum % 10 != 0:
        print("INVALID")

    # Checks start of the string to match correct credit card type
    americanExpress = re.search(r'^34|^37.*', creditCard)
    masterCard = re.search(r'^5[1-5].*', creditCard)
    visa = re.search(r'^4.*', creditCard)

    if americanExpress:
        print("AMEX")
    elif masterCard:
        print("MASTERCARD")
    elif visa:
        print("VISA")


def luhn_algorithm(creditCard):
    nonMultiplied = 0
    multiplied = 0

    # For length of the user input do math with every digit
    for number in range(len(creditCard)):

        # Transform from string to integer
        creditCard = int(creditCard)

        # Take last digit and change whole number to move by 1 place from the end
        nonMultiplied += creditCard % 10
        creditCard = int(creditCard / 10)

        # Take the other last digit and change whole number to move by 1 place
        multipliedDigits = creditCard % 10 * 2
        creditCard = int(creditCard / 10)

        # If number is bigger than 10, add products building that integer
        if multipliedDigits >= 10:
            multipliedDigits = multipliedDigits % 10 + 1

        multiplied += multipliedDigits

    return multiplied + nonMultiplied


main()