program :- read(L1), read(L2), isbagian(L1, L2, X), write(X), nl.
isbagian([],_,1) :- !.
isbagian(_,[],0) :- !.
isbagian([A], [H2|T2], 1) :- A=:=H2, !.
isbagian([A], [H2|T2], 0) :- A=\=H2, !.
isbagian([H1|T1], [H2|T2], X) :- H1=:=H2, isbagian(T1, T2, X).
isbagian([H1|T1], [H2|T2], X) :- H1=\=H2, isbagian([H1|T1], T2, X).
:- program.

% [1,2].
% [5,4,1,2,7,8,2].
