
from cs50 import SQL

db = SQL("sqlite:///finance.db")

usernames = db.execute("SELECT username FROM users")