%a)
%solveA(L-initial list, P-product, GCD-gcd of list, R-result)
%(i,i,i,o)
solveA([], P, GCD, REZ):-
    REZ is div(P, GCD).


solveA([H|T], P, GCD, REZ):-
    GCD1 is gcd(GCD, H),
    P1 is P*H,
    solveA(T, P1, GCD1, REZ).


%(i,i,i,i,o)
%solveB(L-list, E-elem, POZ-currentPoz, CPOZ-power2poz, LR-resultList)
solveB([], _, _, _, []).

solveB([H|T], E, POZ, CPOZ, [H,E|TR]):-
    POZ =:= CPOZ, !,
    POZ1 is POZ+1,
    CPOZ1 is CPOZ*2,
    solveB(T, E, POZ1, CPOZ1, TR).


solveB([H|T], E, POZ, CPOZ, [H|TR]):-
    POZ =\= CPOZ, !,
    POZ1 is POZ+1,
    solveB(T, E, POZ1, CPOZ, TR).




