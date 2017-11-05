
multiply([], _, _).

multiply([H | T], K, [HR | TR]):-
    HR is H*K,
    multiply(T, K, TR).


mycount([], _, 0).

mycount([H | T], E, R):-
    H =:= E,
    mycount(T, E, R2),
    R is R2 + 1.

mycount([H | T], E, R):-
    H =\= E,
    mycount(T, E, R).


addLast([], E, [E]).
addLast([H | T], E, [HR, TR]):-
    HR is H,
    addLast(T, E, TR).



deleteOneOccur([], _, []).

deleteOneOccur([H | T], L,  LR):-
    mycount(L, H, NR),
    NR =:= 1,
    deleteOneOccur(T, L, LR).

deleteOneOccur([H | T], L, [HR | TR]):-
    mycount(L, H, NR),
    NR =\= 1,
    deleteOneOccur(T, L, TR),
    HR is H.

