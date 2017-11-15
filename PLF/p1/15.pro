
solveB([], [], []).

solveB([H|T], [H|TR1], L2):-
    X is mod(H,2),
    X =:= 0,!,
    solveB(T, TR1, L2).

solveB([H|T], L1, [H|TR2]):-
    X is mod(H,2),
    X =\= 0,!,
    solveB(T, L1, TR2).


pozFirstAparence([E|_], E, POZ, POZ):-!.

pozFirstAparence([_|T], E, POZ, RPOZ):-
    POZ1 is POZ+1,
    pozFirstAparence(T, E, POZ1, RPOZ).


solveA(L, LR):-
    solveA(L, L, 1, LR).

solveA([], _, _, []).

solveA([H|T], L, POZ, [H|TR]):-
    pozFirstAparence(L, H, 1, X),
    X =:= POZ,!,
    POZ1 is POZ+1,
    solveA(T, L, POZ1, TR).

solveA([H|T], L, POZ, LR):-
    pozFirstAparence(L, H, 1, X),
    X =\= POZ,!,
    POZ1 is POZ+1,
    solveA(T, L, POZ1, LR).

