import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Correct usage: python dna.py file.csv file.txt")
        return

    # TODO: Read database file into a variable
    database = []

    # Open file from user input
    with open(sys.argv[1]) as csvFile:
        # Write content of the file row by row to new list
        # Every row inside .csv file corresponds to one dictionary inside list
        reader = csv.DictReader(csvFile)
        for name in reader:
            database.append(name)

    # TODO: Read DNA sequence file into a variable
    textFile = open(sys.argv[2], "r")
    sequence = textFile.read()
    textFile.close()


    # TODO: Find longest match of each STR in DNA sequence
    STRData = {}

    # Iterate through first element to write keys inside new dict
    for i in database[0]:
        # Skip name
        if i == "name":
            continue
        # Write keys from database to new dict
        else:
            subsequence = i
            # Use function to declare longest STR match and save it to the correct key
            STR = longest_match(sequence, subsequence)
            STRData[subsequence] = STR

    # TODO: Check database for matching profiles
    count = 0

    # Iterate through dictionaries in list
    for dictionary in database:
        # Reset counter
        count = 0
        # Iterate through keys in dictionaries
        for key in dictionary:
            # If key is name, skip it
            if key == 'name':
                continue
            # Iterate through written STR in dictionary
            for STR in STRData:
                # Check if value is the same, if so count 1 match
                if int(dictionary[key]) == int(STRData[STR]) and key == STR:
                    count += 1
                    # If every value inside dict is matched print name
                    if count == len(STRData):
                        print(dictionary["name"])
                        exit(0)
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
