import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("usage: dna.py data sequence")
        return

    data = []
    results = {}
    with open(sys.argv[1], "r") as file:
        dataf = csv.DictReader(file)
        for r in dataf:
            data.append(r)
            for k in r:
                if k != "name":
                    results[k] = 0

    with open(sys.argv[2], "r") as file:
        for row in file:
            sequence = row

    for k in results:
        results[k] = longest_match(sequence, k)

    for r in data:
        n = 0
        for k in r:
            if k != "name":
                if int(r[k]) != int(results[k]):
                    break
                else:
                    n += 1
                if n == len(results):
                    print(r["name"])
                    return

    print("No match")
    return


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