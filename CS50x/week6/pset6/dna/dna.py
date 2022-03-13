import csv
import sys

def main():

    """
    Currently trying to find the best way to make the command take either large or smalll CSV as input
    And know how to store the subsqs from that first row, to know what to check for later
    """

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    db = open(sys.argv[1], "r")
    reader = csv.DictReader(db)
    
    # Store the subsequences of DNA from the database in a list
    subsequences = reader.fieldnames[1:]
    
    # TODO: Read DNA sequence file into a variable
    sq = open(sys.argv[2], "r")
    sequence = sq.read().rstrip("\n")

    # TODO: Find longest match of each STR in DNA sequence
    longest_matches = {}
    for subsq in subsequences:
        longest_matches[subsq] = longest_match(sequence, subsq)

    # TODO: Check database for matching profiles
    points = 0
    points_needed = len(subsequences)

    for row in reader:
        for subsq in subsequences:
            if int(row[subsq]) == int(longest_matches[subsq]):
                points += 1
        if points == points_needed:
            print(row['name'])
            return
        points = 0
    print("No Match")

    db.close()
    sq.close()


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
