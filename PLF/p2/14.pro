

% funct(L-list, MG-maxGlobal, PSG-posStartGlobal, MC-maxCurent,
% PSC-posStartCurent, P-PozCurrent, MGF-rezMax, PSGF-rezPoz)
% (i, i, i, i, i, i, o, o)

funct([], MG, PSG, _, _, _, MG, PSG).

funct([H|T], MG, PSG, MC, PSC, P, MGF, PSGF):-

    X is mod(H,2),
    P1 is P+1,

    X =:= 0, MC =:= 0,

    PSC is P1,
    MC1 is MC+1,

    funct(T, MG, PSG, MC1, PSC, P1, MGF, PSGF).


funct([H|T], MG, PSG, MC, PSC, P, MGF, PSGF):-

    X is mod(H,2),
    P1 is P+1,

    X =:= 0, MC =\= 0,

    MC1 is MC+1,
    funct(T, MG, PSG, MC1, PSC, P1, MGF, PSGF).



funct([H|T], MG, _, MC, PSC, P, MGF, PSGF):-

    X is mod(H,2),
    P1 is P+1,

    X =:= 1, MG < MC,

    MG1 is MC,
    PSG1 is PSC,
    MC1 is 0,
    PSC1 is 0,

    funct(T, MG1, PSG1, MC1, PSC1, P1, MGF, PSGF).


funct([H|T], MG, PSG, MC, _, P, MGF, PSGF):-
    X is mod(H,2),
    P1 is P+1,

    X =:= 1, MG > MC,
    MC1 is 0,
    PSC1 is 0,

    funct(T, MG, PSG, MC1, PSC1, P1, MGF, PSGF).




