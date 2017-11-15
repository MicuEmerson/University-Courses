solveA([], R):-
    R =:= 1,!,
    write("Even length").

solveA([], R):-
    R =:= 0,!,
    write("Odd length").

solveA([_|T], R):-
    R1 is 1-R,
    solveA(T, R1).
