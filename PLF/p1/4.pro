
apare([], _):-fail.
apare([E|_], E):-!.
apare([H|T], E):-
    H =\= E, !,
    apare(T, E).

solveA([], _, []).

solveA([H|T], L2, [H|TR]):-
    not(apare(L2, H)),!,
    solveA(T, L2, TR).

solveA([H|T], L2, RL):-
    apare(L2, H), !,
    solveA(T, L2, RL).


solveB([], []).

solveB([H|T], [H,1|TR]):-
    X is mod(H, 2),
    X =:= 0, !,
    solveB(T, TR).

solveB([H|T], [H|TR]):-
    X is mod(H, 2),
    X =\= 0, !,
    solveB(T, TR).
