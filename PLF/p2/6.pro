
addBegin(E, L1, [E|L1]).

reverse([], L1, L1).

reverse([H|T], L1, LR):-
    addBegin(H, L1, L2),
    reverse(T, L2, LR).



solveA(L, D, LR):-
    reverse(L, [], L1),
    solveA(L1, D, 0,  LR1),
    reverse(LR1, [], LR).


solveA([], _, C, [C]):-
    C =\= 0, !.

solveA([], _, C, []):-
    C =:= 0, !.

solveA([H|T], D, C, [HR|TR]):-
    HR is mod(H*D+C,10),
    C1 is div(H*D+C,10),
    solveA(T, D, C1, TR).


