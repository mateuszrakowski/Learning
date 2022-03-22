# TODO

def main():
    height = get_height()
    for i in range(height):
        for j in range((height-1)-i):
            print(" ", end="")
        for k in range(i+1):
            print("#", end="")
        print("  ", end="")
        for l in range(i+1):
            print("#", end="")
        print("")


def get_height():
    while True:
        try:
            n = int(input("Height "))
            if n > 0 and n < 9:
                break
            else:
                print("That's not an invalid integer.")
        except ValueError:
            print("That's not an integer!")
    return n

main()