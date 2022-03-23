import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

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
    return render_template("index.html")


"""
Currently Working on this
SitRep:
    - Have amalgamated all of the information necessary to log a stock purchase
    - RN I'm creating the SQL that will save this info
    - I have to decide how these tables will communicated with each other,
    - .schema is printing horizontal and bugging te shit out of me
    - This table will have a lot to do with the /history route and its function
    - So maybe check that out and keep it in mind
"""
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        sym = request.form.get("symbol")
        if sym == "" or None:
            return apology("Input is blank or the symbol does not exist")
        shares = request.form.get("shares")
        if shares < 0:
            return apology("Input is not a positive integer")

        company = lookup(sym)
        name = company["name"]
        price = company["price"]
        symbol = company["symbol"]

        currentCash = int(db.execute("SELECT cash FROM users WHERE username IS ?", session["name"]))

        if (price * shares) < currentCash:
            return apology("You cannot afford the number of shares at the current price.")

        now = datetime.datetime.now().replace(microsecond=0).isoformat().replace("T", " ")

        db.execute("INSERT INTO transactions (symbol, shares, price, transacted) VALUES(?, ?, ?, ?)", symbol, shares, price, now)


        flash(f"Bought {shares} shares of {symbol} symbol!")


        
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        company = lookup(request.form.get("symbol"))
        return render_template("quoted.html", company=company)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    return render_template("register.html")

@app.route("/registration", methods=["GET", "POST"])
def registration():
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

        # Not showing up for some reason
        flash("someone has been registered!")

        return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
