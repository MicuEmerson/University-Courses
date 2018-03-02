
myList = []

def ok():
    nr0 = 0
    nr1 = 0

    for i in myList:
        if i == 0:
            nr0 += 1
        else:
            nr1 += 1

        if(nr1 > nr0):      return 0
        if(nr0 > int(n/2)): return 0
        if(nr1 > int(n/2)): return 0
        
    return 1
            
        
def back(pas):

    if pas == n:
        s = ''
        for i in myList:
            if i == 0:
                s += '('
            else:
                s += ')'
        print(s)

    else:
        for i in range(0,2):
            myList.append(i)
            if ok():
                back(pas+1)
            myList.pop()

            
n = int(input())
back(0)



