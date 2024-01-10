# TODO
from cs50 import get_string


# initialized counters for letters, words, sentences.
letCount = 0
wrdCount = 1
sentCount = 0

# gets input
text = get_string("Text: ")
# loops to increment counters
for i in text:
    if i.isalpha():
        letCount += 1
    elif i == " ":
        wrdCount += 1
    elif i == "." or i == "!" or i == "?":
        sentCount += 1

# calculates reading level
x = round(0.0588 * (letCount / wrdCount * 100) - 0.296 * (sentCount / wrdCount * 100) - 15.8)

# prints ultimatums for outcomes
if x < 1:
    print("Before Grade 1")
elif x >= 16:
    print("Grade 16+")
else:
    print(f"Grade {x}")

print()