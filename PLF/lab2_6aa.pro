
prodL([], _, Q, LR):-
    Q =\= 0,
    LR is [Q|LR].

prodL([H|T], D, Q, LR):-

