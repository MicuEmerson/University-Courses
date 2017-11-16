%(i,i,0)


addFinal([], E, [E]).

addFinal([H|T], E, [H|TR]):-
    addFinal(T,E,TR).

reverse([], []).

reverse([H|T], LR):-
    reverse(T,LR1),
    addFinal(LR1, H, LR).


decrement([E], F, []):-
    E-F =:= 0,!.

decrement([E], F, [E1]):-
    E - F =\= 0,!,
    E1 is E-F.

decrement([H|T], F, [H|TR]):-
    F =:= 0,!,
    decrement(T,F,TR).

decrement([H|T], F, [HR|TR]):-
    F =:= 1,
    H =\= 0,!,
    HR is H-1,
    F1 is 0,
    decrement(T,F1,TR).

decrement([H|T], F, [HR|TR]):-
    F =:= 1,
    H =:= 0,!,
    HR is 9,
    decrement(T,F,TR).

main(L, LR):-
    reverse(L, L1),
    decrement(L1, 1, LR1),
    reverse(LR1, LR).

