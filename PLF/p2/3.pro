
%merge(L1-list, L2-list, LR-resultList)
%(i,i,o)

noDup([], []).
noDup([E], [E]):-!.

noDup([H1,H2|T], LR):-
    H1 =:= H2,!,
    noDup([H2|T], LR).

noDup([H1,H2|T], [HR|TR]):-
    H1 =\= H2,!,
    HR is H1,
    noDup([H2|T], TR).


merge(L1, [], L1):-!.
merge([], L2, L2):-!.

merge([H1|T1], [H2|T2], [H1|TR]):-
    H1 < H2,!,
    merge(T1, [H2|T2], TR).

merge([H1|T1], [H2|T2], [H2|TR]):-
    H1 > H2,!,
    merge([H1|T1], T2, TR).

merge([H1|T1], [H2|T2], [H2|TR]):-
    H1 =:= H2,!,
    merge(T1, T2, TR).


solve(L1, L2, LR):-
    noDup(L1, L11),
    noDup(L2, L22),
    merge(L11, L22, LR).

heterogen([], []).
heterogen([H|T], LR):-
    is_list(H),
    heterogen(T, LR2),
    solve(LR2, H, LR).

heterogen([H|T], LR):-
    number(H),
    heterogen(T, LR).
