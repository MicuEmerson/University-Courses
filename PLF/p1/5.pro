apare([], _):-fail.
apare([E|_], E):-!.
apare([H|T], E):-
    H =\= E, !,
    apare(T, E).


solveA([], L2, L2).

solveA([H|T], L2, LR):-
    apare(L2, H), !,
    solveA(T, L2, LR).

solveA([H|T], L2, [H|TR]):-
    not(apare(L2, H)), !,
    solveA(T, L2, TR).



compute([], _, []).

compute([H|T], E, [[E,H]|TR]):-
    compute(T, E, TR).


solveB([], LR, LR).

solveB([H|T], R, LR):-
    compute(T, H, X),
    append(R, X, R1),
    solveB(T, R1, LR).

