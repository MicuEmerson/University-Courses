def solve(x, y):
    while x:
        digit_x = int(x % 10)
        x = int(x / 10)
        copy_y = y;
        found = 0;
        
        while copy_y:
            digit_y = int(copy_y % 10)
            copy_y = int(copy_y / 10)
            if digit_y == digit_x:
                found = 1
                
        if found == 0:
            return False;
        
    return True;
            
x = int(input("Read the first number: "))
y = int(input("Read the first number: "))
              
if solve(x,y):
    print("They have the property P")
else:
    print("They don't have the property P")
        
        
