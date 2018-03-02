
myList = []
n = 0

def ok(pas):
    nr0 = 0
    nr1 = 0

    for i in range(0,pas):
        if myList[i] == 0:
            nr0 += 1
        else:
            nr1 += 1

        if(nr1 > nr0): return 0
        if(nr1 > int(n/2)): return 0
        if(nr1 > int(n/2)): return 0

    return 1
            
        
def back(pas):

    if pas > n:
        for i in myList:
            if i == 0:
                print('(')
            else:
                print(')')

    else:
        for i in range(0,2):
            myList.append(i)
            if ok(pas):
                back(pas+1)
            myList.pop()
            

n = input()
back(n)


