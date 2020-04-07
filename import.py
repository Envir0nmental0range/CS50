# import.py

import sys, csv

from cs50 import SQL

# check command line arguments
if len(sys.argv) != 2:
    print("Error: need exactly one command line argument for csv file.")
    exit(0)

#name csv file for accessing as original, set up a working list
original = sys.argv[1]
workingList = []

#set workingList to consist of entries where each is a nested list containing all three names (NONE for middle if req'd), house and birth
with open(original, newline = '') as csvfile:
    originalReader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in originalReader:
        end = row[-1].split(",")
        start = row[:-1]
        while len(start) < 2:
            start.append("NONE")
        whole = start + end
        if len(whole) != 5:
            print("LENGTH ERROR.")
            exit(1)
        workingList.append(whole)
del workingList[0]

#set database as db
db = SQL("sqlite:///students.db")
#set first student id to 1
st_id = 1
#loop through working list and insert into database
for r in workingList:

    format_str = """INSERT INTO students (id, first, middle, last, house, birth)
    VALUES ({stid}, "{first}", "{middle}", "{last}", "{house}", "{birth}")"""

    sql_command = format_str.format(stid = st_id, first = r[0], middle = r[1], last = r[2], house = r[3], birth = r[4])

    db.execute(sql_command)
    st_id += 1

#where student has "NONE" listed as middle name, set to NULL in database
db.execute('UPDATE students set middle = NULL WHERE middle = "NONE"')
