
solveB([], _, _, []):-!.

solveB(L, _, 3, L):-!.

solveB([H|T], E, O, RL):-
    H =:= E, !,
    O1 is O+1,
    solveB(T, E, O1, RL).

solveB([H|T], E, O, [H|TR]):-
    H =\= E, !,
    solveB(T, E, O, TR).

