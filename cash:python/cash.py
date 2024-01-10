# TODO
from cs50 import get_float

# global counter variable
dollars = 0

# gets input from user
n = get_float("change owed: ")

# validates input
while n < 0:
    n = get_float("change owed: ")

d = round(n * 100)

# infinite loop for dollars so long as d is greater than 0
while d > 0:
    if d >= 25:
        d -= 25
        dollars += 1
    elif d >= 10:
        d -= 10
        dollars += 1
    elif d >= 5:
        d -= 5
        dollars += 1
    else:
        d -= 1
        dollars += 1

# prints 
print(dollars)
