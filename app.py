import os

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

        # TODO: Add the user's entry into the database
        name = request.form["name"]
        month = request.form["month"]
        day = request.form["day"]
        print(f"Request Payload: {request.form}")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES (%s, %s, %s)", name, month, day)    #SQL script to add to database

        return redirect("/")    #Gotta do this after POST!

    else:

        # TODO: Display the entries in the database on index.html
        # 1. Query database for all of the birthdays
        birthdays = db.execute("select * from birthdays")   # ORM -- Object-Relational Mapper
        # print(birthdays)
        # 2. Pass them into the render template function

        return render_template("index.html", birthdays=birthdays)


