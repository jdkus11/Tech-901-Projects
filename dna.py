import csv
import sys


def main():

    # TODO: Check for command-line usage
    if(len(sys.argv)-1 !=2):
        print("Usage: dna.py {filename.csv} {filename.txt}")
        return

    # TODO: Read database file into a variable
    dna_profiles = []   # This creates a list for all people in the database
    with open(sys.argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        for person in reader:
            dna_profiles.append(person)    # This is adding everyone in as a dictionary

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as sequencefile:
        sequence = sequencefile.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_matches = {}
    for key in dna_profiles[0].keys():
        if key == "name":
            continue
        str_matches[key] = longest_match(sequence, key)


    # TODO: Check database for matching profiles
    for person in dna_profiles:
        match = True
        for key in person.keys():
            if key == "name":
                continue
            if int(person[key]) != str_matches[key]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No Match")


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
