program :- read(L1), read(L2), isprefix(L1, L2, N), write(N), nl.
isprefix([] , _ , 1) :- !.
isprefix(_, [], 0) :- !.
isprefix([H1|T1], [H2|T2], X) :- H1=:=H2, isprefix(T1, T2, X).
isprefix([H1|T1], [H2|T2], 0) :- H1=\=H2, !.
:- program.
