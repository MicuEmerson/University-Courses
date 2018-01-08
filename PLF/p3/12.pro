

%solve(N-dimList, RL-resultList).
%(i,o)
solve(1,[0]):-!.

solve(N, [H1,H2|TR]):-
    N1 is N-1,
    solve(N1,[H2|TR]),
    H2 =\= 0,
    H1 is 0.

solve(N, [H1,H2|TR]):-
    N1 is N-1,
    solve(N1,[H2|TR]),
    H2 =\= 1,
    H1 is 1.

solve(N, [H1,H2|TR]):-
    N1 is N-1,
    solve(N1,[H2|TR]),
    H2 =\= -1,
    H1 is -1.


main(N,LR):-
    N1 is N*2+1,
    findall(LR2, solve(N1,LR2), LR).

%set_prolog_flag(answer_write_options,[max_depth(0)]).
