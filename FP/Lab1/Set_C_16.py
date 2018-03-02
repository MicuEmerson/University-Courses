def largestPerfectNumber(x):
    if x < 6 :
        return 6
    elif x < 28:
        return 28
    elif x < 496:
        return 496
    elif x < 8128:
        return 8128
    elif x < 33550336:
        return 33550336
    else:
        return -1

x = int(input("Read a number: "))

rez = largestPerfectNumber(x)

if(rez == -1):
    print("Number does not exist")
else:
    print(rez)
