from cs50 import get_float

def main():
    dollars = get_dollars()

    quarters = calculate_quarters(dollars)
    dollars = dollars - quarters * 0.25

    dimes = calculate_dimes(dollars)
    dollars = dollars - dimes * 0.10

    nickels = calculate_nickels(dollars)
    dollars = dollars - nickels * 0.05

    pennies = calculate_pennies(dollars)

    coins = quarters + dimes + nickels + pennies
    print(round(coins))

def get_dollars():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            break
        else:
            print("That's not a valid number!")
    return n


def calculate_quarters(dollars):
    quarters = round(dollars/0.25, 1)
    return int(quarters)

def calculate_dimes(dollars):
    dimes = round(dollars/0.10, 1)
    return int(dimes)

def calculate_nickels(dollars):
    nickels = round(dollars/0.05, 1)
    return int(nickels)

def calculate_pennies(dollars):
    pennies = round(dollars/0.01, 1)
    return int(pennies)


main()