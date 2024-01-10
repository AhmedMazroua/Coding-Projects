#Takes in parameter and pulls the name assuming the user input is formated as prompted
def NAME(v):
    n = v.split(" ")
    n.pop()
    name = n
    name = ' '.join(map(str, name)).title()

    return name

#Takes in parameter and pulls the month assuming the user input is formated as prompted
def MONTH(v):

    m = v.split(" ")
    bday = m.pop()

    birDay = []
    for i in bday:
        birDay.append(i)

    month = birDay[:2]
    month = ''.join(map(str, month))

    return month
#Takes in parameter and pulls the day assuming the user input is formated as prompted
def DAY(v):
    d = v.split(" ")
    bday = d.pop()

    birDay = []
    for i in bday:
        birDay.append(i)

    day = birDay[2:4]
    day= ''.join(map(str, day))

    return day
