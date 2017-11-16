

%trebe sa fac reverse pe lista
%dupa ce le adun, nu pot pur si simplu sa concantez lista mai mare
%ci trebe sa fac o alta functie de aduna o lista cu un carry

adunaCuCarry([], C, [C]):-
   C =\= 0,!.

adunaCuCarry([], C, []):-
    C =:= 0,!.

adunaCuCarry([H|T], C, [HR|TR]):-
    HR is mod(H+C,10),
    C1 is div(H+C,10),
    adunaCuCarry(T, C1, TR).

sumL([], L2, C, LR):-
    adunaCuCarry(L2, C, LR),!.

sumL(L1, [], C, LR):-
    adunaCuCarry(L1, C, LR),!.


sumL([H1|T1], [H2|T2], C, [HR|TR]):-
    HR is mod(H1+H2+C,10),
    C1 is div(H1+H2+C,10),
    sumL(T1, T2, C1, TR).


addBegin(L, E, [E|L]).

reverse([], LR, LR).

reverse([H|T], LR, LF):-
    addBegin(LR, H, LR1),
    reverse(T, LR1, LF).


main(L1, L2, LSUM):-
    reverse(L1, [], L11),
    reverse(L2, [], L22),
    sumL(L11, L22, 0, LSUM1),
    reverse(LSUM1, [], LSUM).

