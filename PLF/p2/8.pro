reverse([],L,L).

reverse([H|T], L, LR):-
    L1 = [H|L],
    reverse(T,L1,LR).


inc([], C, [C]):-
    C =\= 0,!.

inc([], C, []):-
    C =:= 0,!.

inc([H|T], C, [HR|TR]):-
    HR is mod(H+C,10),
    C1 is div(H+C,10),
    inc(T,C1,TR).

main(L,LR):-
    reverse(L,[],L1),
    inc(L1,1,LR1),
    reverse(LR1, [], LR).



