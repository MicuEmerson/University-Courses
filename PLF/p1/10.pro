
solveB([], _, R, R).

solveB([H|T], X, R, RF):-
    X =:= 0, !,
    R1 is R+H,
    X1 is 1-X,
    solveB(T, X1, R1, RF).


solveB([H|T], X, R, RF):-
    X =:= 1, !,
    R1 is R-H,
    X1 is 1-X,
    solveB(T, X1, R1, RF).



mountain_dec([_]):-!.

mountain_dec([H1,H2|T]):-
    H1 > H2,!,
    mountain_dec([H2|T]).

mountain_inc([H1,H2|T]):-
    H1 < H2,!,
    mountain_inc([H2|T]).

mountain_inc([H1,H2|T]):-
    H1 > H2,!,
    mountain_dec([H2|T]).

mountain([H1,H2|T]):-
    H1 < H2,
    mountain_inc([H2|T]).


valley_inc([_]):-!.

valley_inc([H1,H2|T]):-
    H1 =< H2, !,
    valley_inc([H2|T]).

valley_dec([H1,H2|T]):-
    H1 >= H2, !,
    valley_dec([H2|T]).

valley_dec([H1,H2|T]):-
    H1 =< H2, !,
    valley_inc([H2|T]).

valley([H1,H2|T]):-
    H1 >= H2,
    valley_dec([H2|T]).




