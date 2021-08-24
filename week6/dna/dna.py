import csv
import os
import sys


def count(key, sequence):
    longest = tmp = 0
    lkey = len(key)
    lseq = len(sequence)
    i = 0
    while i + lkey <= lseq:
        if sequence[i:i + lkey] == key:
            i += lkey
            tmp += 1
            longest = max(longest, tmp)
        else:
            i += 1
            tmp = 0
    return longest


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py path/to/database path/to/sequence")
    if not os.path.isfile(sys.argv[1]):
        sys.exit("Error: Database file not found")
    elif not os.path.isfile(sys.argv[2]):
        sys.exit("Error: Sequence file not found")
    else:
        db = {}
        keys = []
        with open(sys.argv[1], 'r') as f:
            for line in csv.DictReader(f):
                name = line['name']
                person = {}
                for key in line.keys():
                    if key != 'name':
                        person[key] = int(line[key])
                        keys.append(key)
                db[name] = person
        with open(sys.argv[2], 'r') as f:
            seq = f.read().strip('\n')

    counts = {k: 0 for k in set(keys)}
    for key in counts.keys():
        counts[key] = count(key, seq)
    for k, v in db.items():
        if v == counts:
            print(k)
            break
    else:
        print('No match')


if __name__ == "__main__":
    main()
