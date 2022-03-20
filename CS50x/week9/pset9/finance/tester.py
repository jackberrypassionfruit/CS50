
from cs50 import SQL
from helpers import lookup

db = SQL("sqlite:///finance.db")

# usernames = db.execute("SELECT username FROM users")

rows = db.execute("SELECT * FROM users WHERE username IS 'dad'")

print(rows)