%occurences(L-list, E-elem, O-occurences, OF-finalResult)
%(i, i, i, o).

occurences([], _, O, O).

occurences([H|T], E, O, OF):-
    H =:= E, !,
    O1 is O+1,
    occurences(T, E, O1, OF).

occurences([H|T], E, O, OF):-
    H =\= E, !,
    occurences(T, E, O, OF).


solveA([], _, []).

solveA([H|T], L, [H|TR]):-
    occurences(L, H, 0, 1), !,
    solveA(T, L, TR).

solveA([H|T], L, RL):-
    occurences(L, H, 0, X), !,
    X =\= 1, !,
    solveA(T, L, RL).


%(i,o) and return false if we give an empty list
getMax([H|T], RM):-
    getMax(T, H, RM).

%(i, i, o)
getMax([], M, M).

getMax([H|T], M, RM):-
    H >= M, !,
    getMax(T, H, RM).

getMax([H|T], M, RM):-
    H < M, !,
    getMax(T, M, RM).


%(i, o)
solveB(L, LR):-
    getMax(L, M),
    solveB(L, M, LR).

%(i, i, o)
solveB([], _, []).

solveB([H|T], M, LR):-
    H =:= M, !,
    solveB(T, M, LR).

solveB([H|T], M, [H|TR]):-
    H =\= M, !,
    solveB(T, M, TR).



