# TODO
# imports function from c library
from cs50 import get_int

# asks for height of pyramid
n = get_int("whats the height?: ")

# conditional loop to not accept intergers from outside desired range
while n <= 0 or n > 8:
    n = get_int("whats the height?: ")

# initialized value of J
j = 1

# prints pyramid using range() function on a indexed i value and a recursive j value
for i in range(n - 1, -1, -1):
    print((" " * i)+("#" * j))
    j = j + 1

