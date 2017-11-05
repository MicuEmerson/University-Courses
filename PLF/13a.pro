apare([H|_], H).
apare([H|T], E):-
    H =\= E, !,
    apare(T, E).


% listToSet(L - list, RL - result list)
% listToSet model flow: (i,o) (i,i)
listToSet([],[]).

listToSet([H | T],[HR | TR]):-
    \+ apare(T, H), !,
    HR is H,
    listToSet(T,TR).

listToSet([_ | T],LR):-
    listToSet(T, LR).

test1:-
    listToSet([1,2,3,3,4,2], [1,3,4,2]),
    listToSet([3,3,3], [3]),
    listToSet([1,2,3,4], [1,2,3,4]),
    listToSet([1,2,3], [1,2,3]),
    listToSet([], []),
    write("Passed all tests").


