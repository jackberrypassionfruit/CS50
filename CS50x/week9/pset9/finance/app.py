import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# My Kindling
registrants = {}


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if not session.get("name"):
        return redirect("/login")
    portfolios_table = db.execute("SELECT * FROM portfolios WHERE user_id IS ?", session["user_id"])
    current_cash = db.execute("SELECT cash FROM users WHERE id IS ?", session["user_id"])[0]["cash"]

    return render_template("index.html", portfolios_table=portfolios_table, lookup=lookup, current_cash=current_cash)


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        """Register user"""

        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        users = db.execute("SELECT * FROM users")

        if username in [user["username"] for user in users] or username == "":
            return apology("Username blank or already exists", 403)

        if password != confirmation or password == "":
            return apology("Passwords do not match or are blank", 403)

        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, generate_password_hash(password))

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["name"] = rows[0]["username"]

        # Showing up now, but wasn't before I made sure to log in user on registration
        flash(f"{session['name']} has been registered and logged in!")

        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["name"] = rows[0]["username"]

        # Flashing!
        flash("Logged In!")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        company = lookup(request.form.get("symbol"))
        return render_template("quoted.html", company=company)
    else:
        return render_template("quote.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        company = lookup(request.form.get("symbol"))
        symbol = company["symbol"]
        name = company["name"]
        new_shares = request.form.get("shares")
        if not new_shares:
            return redirect("/buy")
        new_shares = int(new_shares)
        transaction_time = datetime.now().replace(microsecond=0).isoformat().replace("T", " ")
        current_cash = db.execute("SELECT cash FROM users WHERE id IS ?", session["user_id"])[0]["cash"]
        float_price = company["price"]
        sql_price = int(float_price * 100) # Converts currency float to workable integer for sql ex. 47.62 --> 4762
        # Reminder, this is how users.cash (ie. current_cash) is stored in finance.db

        # Also, the price here is stored in "transactions", but not in "portfolios"
        # That changes in real time

        if current_cash < new_shares*sql_price:
            return apology("You cannot afford the number of shares at the current price.", 403)

        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, transaction_time) VALUES(?, ?, ?, ?, ?, ?)", session["user_id"], symbol, name, new_shares, sql_price, transaction_time)
        
        # Use list comprehsion to create a list of the companies that a user owns stocks in
        longs = [company["symbol"] for company in db.execute("SELECT symbol FROM portfolios WHERE user_id IS ?", session["user_id"])]
        
        if symbol in longs:
            current_shares = db.execute("SELECT shares FROM portfolios WHERE user_id IS ? AND symbol IS ?", session["user_id"], symbol)[0]["shares"]
            current_shares += new_shares
            db.execute("UPDATE portfolios SET shares = ? WHERE user_id IS ? AND symbol IS ?", current_shares, session["user_id"], symbol)
        else:
            db.execute("INSERT INTO portfolios (user_id, symbol, name, shares) VALUES(?, ?, ?, ?)", session["user_id"], symbol, name, new_shares)
        
        # Subtract the stock value from the user's cash value
        current_cash -= (new_shares * sql_price)
        db.execute("UPDATE users SET cash = ? WHERE id IS ?", current_cash, session["user_id"])
        
        flash("Bought some stonks!")


        return redirect("/")
    else:
        return render_template("buy.html")
    


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Use list comprehsion to create a list of the companies that a user owns stocks in
    longs = [company["symbol"] for company in db.execute("SELECT symbol FROM portfolios WHERE user_id IS ?", session["user_id"])]

    if request.method == "POST":
        # 2 Do 2 things:
            # 1. Remove stock from my portfolio
            # 2. Increase my cash by the amount it was worth at the time

        company = lookup(request.form.get("symbol"))
        symbol = company["symbol"]
        name = company["name"]
        selling_shares = request.form.get("shares")
        if not selling_shares:
            return redirect("/sell")
        selling_shares = -1 * abs(int(selling_shares))
        transaction_time = datetime.now().replace(microsecond=0).isoformat().replace("T", " ")
        current_cash = db.execute("SELECT cash FROM users WHERE id IS ?", session["user_id"])[0]["cash"]
        float_price = company["price"]
        sql_price = int(float_price * 100) # Converts currency float to workable integer for sql ex. 47.62 --> 4762
        
      
        if symbol in longs or selling_shares > 0:
            #1
            current_shares = db.execute("SELECT shares FROM portfolios WHERE user_id IS ? AND symbol IS ?", session["user_id"], symbol)[0]["shares"]
            
            current_shares += selling_shares
            
            if current_shares < 0:
                return apology("You don't have that many shares to sell", 403)
            elif current_shares == 0:
                db.execute("DELETE FROM portfolios WHERE user_id IS ? AND symbol IS ?", session["user_id"], symbol)
            else:
                db.execute("UPDATE portfolios SET shares = ? WHERE user_id IS ? AND symbol IS ?", current_shares, session["user_id"], symbol)

            db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, transaction_time) VALUES(?, ?, ?, ?, ?, ?)", session["user_id"], symbol, name, selling_shares, sql_price, transaction_time)

            #2
            current_cash -= sql_price * selling_shares
            db.execute("UPDATE users SET cash = ? WHERE id IS ?", current_cash, session["user_id"])

            flash("Sold some stonks!")


            return redirect("/")

        else:
            return apology("Number of shares must be positive, and you must own that many shares of the stock")
        
    else:
        return render_template("sell.html", longs=longs)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    transactions_table = db.execute("SELECT * FROM transactions WHERE user_id IS ?", session["user_id"])

    return render_template("history.html", transactions_table=transactions_table, lookup=lookup)


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/profile", methods=["GET", "POST"])
def profile():
    """Manage account details"""

    if request.method == "post":
        pass
    else:
        current_cash = db.execute("SELECT cash FROM users WHERE id IS ?", session["user_id"])[0]["cash"]
        return render_template("profile.html", current_cash=current_cash)


@app.route("/addCash", methods=["GET", "POST"])
def addCash():
    """Manage account details"""
    current_cash = db.execute("SELECT cash FROM users WHERE id IS ?", session["user_id"])[0]["cash"]
    secret_code = "johnismyfavoritestudent"

    new_cash = int(request.form.get("new_cash"))
    secret = request.form.get("secret")

    if secret != secret_code:
        flash("You forgot the secret code!")
        return redirect("/profile")
    
    # Add new_cash to user's account
    current_cash += 100 * new_cash
    db.execute("UPDATE users SET cash = ? WHERE id IS ?", current_cash, session["user_id"])
    
    flash(f"Added ${new_cash} to account ")
    return redirect("/profile")


@app.route("/changePassword", methods=["GET", "POST"])
def changePassword():

    old = request.form.get("old")
    new = request.form.get("new")
    again = request.form.get("again")

    if new != again:
        flash("Passwords aren't the same!")
        return redirect("/profile")

    # Change Password
    db.execute("UPDATE users SET hash = ? WHERE id IS ?", generate_password_hash(new), session["user_id"])
    flash("Password Changed")
    return redirect("/profile")


# @app.route("/buysell", methods=["GET", "POST"])
# def buysell():
#     shares = request.form.get("shares")
#     symbol = request.form.get("symbol") 
    
#     db.execute("SELECT symbol FROM portfolios WHERE user_id IS ?", session["user_id"])

    
    
