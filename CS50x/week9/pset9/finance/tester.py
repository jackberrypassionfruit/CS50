
from cs50 import SQL
from helpers import lookup

db = SQL("sqlite:///finance.db")

# usernames = db.execute("SELECT username FROM users")

# rows = db.execute("SELECT * FROM portfolios")

print([company["symbol"] for company in db.execute("SELECT symbol FROM portfolios WHERE user_id IS 1")])

# print(int(float(lookup("aapl")["price"]) * 100))

# print(type(lookup("msft")["price"]))

