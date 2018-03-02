def isPrim(x):
    
    if (x % 2 == 0 and x != 2) or x <= 1:
        return False;
    
    for i in range(3, x, 2):
        if (x % i) == 0:
            return False
        
    return True

def nextLargerPrimNumber(x):

    if x < 0:
        return 2
    while isPrim(x) == False:
         x = x + 1;
         
    return x;


x = int(input("Read a number: "))

print(nextLargerPrimNumber(x+1))







