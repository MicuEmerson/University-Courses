
subset([], []).
subset([H|T], [H|TR]):-
    subset(T, TR).

subset([_|T], LR):-
    subset(T, LR).


check([_]):-!.
check([H1,H2|T]):-
    H1 < H2,
    check([H2|T]).


solve(L, LR):-
    subset(L, LR),
    check(LR).

main(L, LR):-
    findall(X, solve(L, X), LR).
