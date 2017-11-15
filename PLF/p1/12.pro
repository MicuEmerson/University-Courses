
solveA([], _, _, []).

solveA([H|T], E, L1, [L1|LR]):-
    H =:= E,!,
    solveA(T, E, L1, LR).

solveA([H|T], E, L1, [H|TR]):-
    H =\= E, !,
    solveA(T, E, L1, TR).


solveAA([], _, _, []).

solveAA([H|T], E, L1, LR):-
    H =:= E, !,
    solveAA(T, E, L1, LR1),
    append(LR1, L1, LR).



solveAA([H|T], E, L1, [H|TR]):-
    H =\= E, !,
    solveAA(T, E, L1, TR).

