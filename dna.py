#dna.py
import sys, re, csv

if len(sys.argv) != 3:
    print("Error: Requires exactly two command line arguments.")
    exit(1)

peopleFile = sys.argv[1]
sequence = sys.argv[2]
try:
    f = open(sequence, "r")
except FileNotFoundError:
    print("File not present in this directory.")
    exit(1)

if f.mode == 'r':
    test = f.read()
else:
    print("File read error.")
    exit(1)

peopleList = []
workingList = []

with open(peopleFile, newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in reader:
        peopleList.append(row)

for i in range(len(peopleList)):
    res = ",".join(peopleList[i])
    res = res.split(",")
    workingList.append(res)

repeats = ['matches']
tester = workingList[0][1:]
dnaCount = len(tester)

for i in range(dnaCount):
    matchCount = 0
    length = len(tester[i])
    multiples = len(test) // length
    while multiples > matchCount:
        sequence = multiples * tester[i]
        if sequence in test:
            matchCount = multiples
        multiples -= 1
    repeats.append(str(matchCount))

for subList in workingList:
    if subList[1:] == repeats[1:]:
        print(subList[0])
        exit(0)

print("No match")
exit(0)
