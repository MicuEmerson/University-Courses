
sumCons(_, 0, []).

sumCons(N, SUM, [N|T]):-
    SUM >= N,
    SUM1 is SUM - N,
    N1 is N+1,
    sumCons(N1, SUM1, T).

sumCons(N, SUM, LR):-
    SUM >= N,
    N1 is N+1,
    sumCons(N1, SUM, LR).

main(N, SUM, LR):-
    findall(X, sumCons(N, SUM, X), LR).
