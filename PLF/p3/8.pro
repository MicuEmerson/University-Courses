
generam(K, N, 0,[]):-
    K is N+1,!.

generam(K, N, OK, [1|T]):-
    OK >= 0,
    K =< N,
    K1 is K+1,
    OK1 is OK+1,
    generam(K1, N, OK1, T).

generam(K, N, OK, [0|T]):-
    OK >= 0,
    K =< N,
    K1 is K+1,
    OK1 is OK-1,
    generam(K1, N, OK1, T).




main(N, LR):-
    findall(X, generam(1, N, 0, X), LR).
