
% varianta recursiva fara listaColectoare
% functie(L-list, E-number, L1-list, LR-resultList)
% (i,i,i,o)
%
functie([], _, _, []):-!.

functie([H|T], E, L1, LR):-
    H =:= E,!,
    functie(T, E, L1, LR2),
    append(L1, LR2, LR).

functie([H|T], E, L1, [HR|TR]):-
    H =\= E,!,
    functie(T, E, L1, TR),
    HR is H.

%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
%varianta cu listaColectoare

addFinal([],E,[E]).
addFinal([H|T], E, [H|TR]):-
    addFinal(T, E, TR).

% funct(L-listaInitiala, E-elem, L1-listaDeInlocuit, LR-listaColectoare,
% LRF-listaRezultatFinal)
% (i, i, i, i, o)
funct([], _, _, LRF, LRF):-!.

funct([H|T], E, L1, LR, LRF):-
    H =:= E,!,
    append(LR, L1, LR2),
    funct(T, E, L1, LR2, LRF).

funct([H|T], E, L1, LR, LRF):-
    H =\= E,!,
    addFinal(LR, H, LR2),
    funct(T, E, L1, LR2, LRF).
