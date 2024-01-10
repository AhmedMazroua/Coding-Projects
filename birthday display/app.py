import os

from func import NAME, MONTH, DAY
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        #Gathers input from page into a variable we can manipulate
        val = request.form["response"]

        #parses for name, month, and day with functions from func module
        name = NAME(val)
        month = MONTH(val)
        day = DAY(val)


        #Adds the user's entry into the database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (:name, :month, :day)",
                   name=name, month=month, day=day)

        return redirect("/")

    else:

        # Displays the entries in the database on index.html
        table = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", table=table)


