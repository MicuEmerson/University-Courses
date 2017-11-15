
solveB([], _, R, R).

solveB([H|T], X, R, RF):-
    X =:= 0, !,
    R1 is R+H,
    X1 is 1-X,
    solveB(T, X1, R1, RF).


solveB([H|T], X, R, RF):-
    X =:= 1, !,
    R1 is R-H,
    X1 is 1-X,
    solveB(T, X1, R1, RF).
