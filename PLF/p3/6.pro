
minsert([], E, [E]).
minsert([H|T], E, [E, H|T]).
minsert([H|T], E, [H|TR]):-
    minsert(T, E, TR).


perm([], []).

perm([H|T], LR):-
   perm(T, LR2),
   minsert(LR2, H, LR).


combinari(_, 0, []).

combinari([H|T], K, [H|TR]):-
    K > 0,
    K1 is K-1,
    combinari(T, K1, TR).

combinari([_|T], K, LR):-
    K > 0,
    combinari(T, K, LR).


arr(L, K, LR):-
    combinari(L, K, LR1),
    perm(LR1, LR).


main(L, K, LR):-
    findall(X, arr(L, K, X), LR).
