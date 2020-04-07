#roster.py
import sys
from cs50 import SQL

# check command line arguments
if len(sys.argv) != 2:
    print("Error: need exactly one command line argument for house.")
    exit(0)

#theHouse is sys.argv[1], set up database access
theHouse = sys.argv[1]
db = SQL("sqlite:///students.db")

format_str = 'SELECT first, middle, last, birth FROM students WHERE house = "{house}" ORDER BY last, first'
sql_command = format_str.format(house = theHouse)
outputList = db.execute(sql_command)

for i in range(len(outputList)):
    iterList = list(outputList[i].values())
    iterList[-1] = str(iterList[-1])
    iterList[2] += ","
    if iterList[1] == None:
        print(iterList[0], iterList[2], "born", iterList[3])
    else:
        print(iterList[0], iterList[1], iterList[2], "born", iterList[3])
