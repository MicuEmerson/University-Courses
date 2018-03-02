
contains([E], E):-!.

contains([E|_], E):-!.

contains([H|T], E):-
    H =\= E,
    contains(T, E).


listToSet([], []).


f(1):-fail.

f(2):-
!,
f(1).

f(2):-
write("offf").

f(3):-
write("Yeeey"),
f(2).

f(3):-
write("Hello").

mountain_desc([_]).

mountain_desc([H1,H2|T]):-
    H1 > H2,
    mountain_desc([H2|T]).

mountain_inc([H1,H2 |T ]):-
    H1 < H2,
    mountain_inc([H2|T]).

mountain_inc([H1, H2|T]):-
    H1 > H2,
    mountain_desc([H2|T]).


mountain([H1,H2|T]):-
    H1 < H2,
    mountain_inc([H2|T]).

inlocuire([], _, _, []).
inlocuire([H|T], E, L1, [H|TR]):-
    number(H),
    H =\= E,
    inlocuire(T,E,L1,TR).

inlocuire([H|T], E, L1, LR):-
    number(H),
    H =:= E,
    inlocuire(T,E,L1,LR2),
    append(L1, LR2, LR).

inlocuire([H|T], E, L1, LR):-
    is_list(H),
    inlocuire(H, E, L1, LR2),
    inlocuire(T, E, L1, LR3),
    LR = [LR3|LR2].




