from sys import argv
import sqlite3

con = sqlite3.connect('fiftyville.db')
cur = con.cursor()

f = open(argv[1], 'r')
code = f.read()

# print(code)
print(cur.execute(code).fetchall())

f.close()