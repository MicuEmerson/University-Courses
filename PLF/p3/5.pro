
subset(K , N, []):-
    K is N+1,!.


subset(K, N, [K|TR]):-
    K1 is K+1,
    subset(K1, N, TR).

subset(K, N, LR):-
    K1 is K+1,
    subset(K1, N, LR).


check([_], _):-!.
check([H1,H2|T], M):-
    abs(H1-H2, AUX),
    AUX >= M,
    check([H2|T], M).


problem(N, M, LR):-
    subset(1, N, LR),
    length(LR, LEN),
    LEN > 1,
    check(LR, M).

main(N,M, LR):-
    findall(X, problem(N,M, X), LR).
