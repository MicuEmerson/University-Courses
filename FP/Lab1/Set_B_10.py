def prodProperFactors(x):
    
    prod = 1;
    
    for i in range(2, x):
        if x % i == 0:
            prod = prod * i
            
    return prod

x = int(input("Read a number: "))

print(prodProperFactors(x))
