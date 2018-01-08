
combinari(_, 0, []).

combinari([H|T], K, [H|TR]):-
    K > 0,
    K1 is K-1,
    combinari(T, K1, TR).

combinari([_|T], K, LR):-
    K > 0,
    combinari(T, K, LR).

main(L, K, LR):-
    findall(X,combinari(L, K, X), LR).
