program :- read(L1), read(L2), gabung(L1, L2, X), write(X), nl.
gabung(A, [], A) :- !.
gabung([], A, A) :- !.
gabung([H|T1], [H2|T2], [H|T3]) :-
    H=<H2,
    gabung(T1, [H2|T2], T3).
gabung([H|T1], [H2|T2], [H2|T3]) :-
    gabung([H|T1], T2, T3).
:- program.

% 12345
