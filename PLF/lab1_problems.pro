%1 a)

divLC(A, B, R):-
    R is (A*B)/gcd(A,B).

divLC_List([], 1):-!.

divLC_List([H | T], R):-
    divLC_List(T, R2),
    divLC(H, R2, R).


%1 b)

addEndElem([], E, [E]).
addEndElem([H|T], E, [H | TR]):-
    addEndElem(T,E,TR).


%%%%%%%%%%%%%%%%%%%%%



%2 a)

removeOcc([], _, []).
removeOcc([H|T], E, LR):-
    H =:= E,
    removeOcc(T, E, LR).

removeOcc([H|T], E, [HR|TR]):-
    H =\= E,
    HR is H,
    removeOcc(T, E, TR).

occurence([], _, 0).

occurence([H| T], E, R):-
    H =:= E,
    occurence(T, E, R2),
    R is R2 + 1.

occurence([H|T], E, R):-
    H =\= E,
    occurence(T, E, R).


%3 a)

repetitiveElem([],_,[]).
repetitiveElem([H|T], L, LR):-
    occurence(L, H, X),
    X =\= 1,
    repetitiveElem(T, L, LR).

repetitiveElem([H|T], L, [H|TR]):-
    occurence(L, H, 1),
    repetitiveElem(T, L, TR).


%6 a)

apare([],_):-
    false.
apare([H|T], E):-
    H =:= E,
    !.
apare([H|T], E):-
    H =\= E,
    apare(T, E).


testSet([]):-
    1=:=1.  %true fact

testSet([H|T]):-
    not(apare(T, H)),
    testSet(T).

%L E p LR

remove3([], _, _, []).

remove3(L1, _, 3, L1).

remove3([H|T], E, P, [HR|TR]):-
    H =\= E,
    HR is H,
    remove3(T, E, P, TR).

remove3([H|T], E, P, L2):-
    H =:= E,
    P1 is P+1,
    remove(T, E, P1, L2).


% N-M range and LR output list

rangeList(N, N, []).
rangeList(N, M, [H|T]):-
    H is N,
    N1 is N+1,
    rangeList(N1, M, T).



















