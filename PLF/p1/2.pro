
solveA([], _, []).

solveA([H|T], E, LR):-
    H =:= E, !,
    solveA(T, E, LR).

solveA([H|T], E, [H|TR]):-
    H =\= E, !,
    solveA(T, E, TR).



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


%solveB(L-list, L-copyOfList, RL-resultList)
%(i,i,o)
solveB([],_,[]).

solveB([H|T], L, [[H,X]|TR]):-
    occurences(T, H, 0, 0), !,
    occurences(L, H, 0, X),
    solveB(T, L, TR).

solveB([H|T], L, LR):-
    occurences(T, H, 0, Y), !,
    Y =\= 0, !,
    solveB(T, L, LR).

