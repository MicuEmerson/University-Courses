fact2(0,1):- !.
fact2(N,F):- N1 is N-1,
    fact2(N1,F1),
    F is N*F1.
