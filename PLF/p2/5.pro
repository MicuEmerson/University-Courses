

solveA([], _, _, []):-!.

solveA([H|T], E, L1, [H|TR]):-
    H =\= E, !,
    solveA(T, E, L1, TR).

solveA([H|T], E, L1, [L1|TR]):-
    H =:= E,!,
    solveA(T, E, L1, TR).


solveAA([], _, _, []):-!.

solveAA([H|T], E, L1, [H|TR]):-
    H =\= E,
    solveAA(T, E, L1, TR).

solveAA([H|T], E, L1, L2):-
    H =:= E,
    append(L2, L1, L3),
    solveAA(T, E, L1, L3).



noHet([], []).

noHet([H|T], [H|TR]):-
    number(H),!,
    noHet(T, TR).

noHet([H|T], LR):-
    is_list(H),!,
    noHet(H, LR),
    noHet(T, LR).


main(L, LR):-
    solveA(L, X),
    noHet(X, LR).


