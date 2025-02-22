# Book
# Attributes: title, author, price

class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price

    def print_info(self):
        print(f"Title: {self.title}")
        print(f"Author:{self.author}")
        print(f"Price: ${self.price}")
        print("----------------------")

    def __add__(self, other):   # Used to make the sum function work
        if other == 0:
            return self.price
        else:
            return self.price + other

    def __radd__(self, other):  # Used to make the sum function work
        if other == 0:
            return self.price
        else:
            return self.__add__(other)

bookshelf = []

bookshelf.append(Book("Wind and Truth", "Brandon Sanderson", 40.99))
bookshelf.append(Book("Rhythm of War", "Brandon Sanderson", 35.99))
bookshelf.append(Book("Oathbringer", "Brandon Sanderson", 35.99))

for book in bookshelf:
    book.print_info()

print(f"Total cost of your libaray is ${sum(bookshelf)}")

# book1 = Book("Wind and Truth", "Brandon Sanderson", 40.99)
# book2 = Book("Rhythm of War", "Brandon Sanderson", 35.99)
# book3 = Book("Oathbringer", "Brandon Sanderson", 35.99)
# book4 = Book("Words of Radiance", "Brandon Sanderson", 30.99)
# book5 = Book("The Way of Kings", "Brandon Sanderson", 20.99)

# book1.print_info()
# book2.print_info()

# print(f"Total cost of your libaray is ${round(book1.price + book2.price + book3.price + book4.price + book5.price, 2)}")
