gcd1(X,0):-!.

gcd1(X,Y):-
    Z is X mod Y,
    gcd1(Y,Z).

