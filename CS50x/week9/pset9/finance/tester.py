
from cs50 import SQL
from helpers import lookup, usd
from flask import Flask, flash, redirect, render_template, request, session


db = SQL("sqlite:///finance.db")

# usernames = db.execute("SELECT username FROM users")

# rows = db.execute("SELECT * FROM portfolios")

# print([company["symbol"] for company in db.execute("SELECT symbol FROM portfolios WHERE user_id IS 1")])

# print(int(float(lookup("aapl")["price"]) * 100))

<<<<<<< HEAD
print(lookup("AAPL"))
=======
print(type(usd(lookup("msft")["price"])))
>>>>>>> 33336716fa87234eb21b8bc4f95bb51b9c250ee8

# print(db.execute("SELECT cash FROM users WHERE id = 9")[0]["cash"])