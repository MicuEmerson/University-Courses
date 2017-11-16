
minElem([H|T], MN):-
    minElem(T, H, MN).

minElem([], MN, MN).

minElem([H|T], MN, MNF):-
    H < MN,!,
    minElem(T, H, MNF).

minElem([H|T], MN, MNF):-
    H >= MN, !,
    minElem(T, MN, MNF).



removeElem([], _, []).

removeElem([H|T], E, RL):-
    H =:= E,!,
    removeElem(T, E, RL).

removeElem([H|T], E, [H|TR]):-
    removeElem(T, E, TR).


remove2([E|T], E, T):-!.

remove2([H|T], E, [H|TR]):-
    remove2(T, E, TR).



solveA([], []):-!.


solveA(L, [MN|TR]):-
    minElem(L, MN),
    remove2(L, MN, L1),
    solveA(L1, TR).


