
divizori(1,_,[]):-!.
divizori(N,C,[]):-
    N =:= C,!.

divizori(N,C,[HR|TR]):-
    X is mod(N,C),
    X =:= 0,!,
    HR is C,
    C1 is C+1,
    divizori(N, C1, TR).

divizori(N, C, LR):-
    X is mod(N,C),
    X =\= 0,!,
    C1 is C+1,
    divizori(N, C1, LR).


divAfterNumber([], []).

divAfterNumber([H|T], LR):-
    divAfterNumber(T, LR1),
    divizori(H, 2, X),
    append(X, LR1, LR2),
    LR = [H|LR2].


heterogen([], []):-!.

heterogen([H|T], [HR|TR]):-
    is_list(H),!,
    divAfterNumber(H, HR),
    heterogen(T,TR).

heterogen([H|T], [HR|TR]):-
    number(H),!,
    HR is H,
    heterogen(T,TR).
