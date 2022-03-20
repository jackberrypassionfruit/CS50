from cs50 import SQL

db = SQL("sqlite:///birthdays.db")

people = db.execute("SELECT * FROM birthdays")

print(people)