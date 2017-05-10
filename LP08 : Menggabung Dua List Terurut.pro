program :- read(List), hapus(List, B), write(B), nl.
hapus([], []) :- !.
hapus([A], [A]) :- !.
hapus([H1|[H2|T]], [H1|X]) :- H1=\=H2, hapus([H2|T], X).
hapus([H1|[H2|[H3|T]]], X) :- H1=:=H2, H2=:=H3, hapus([H2|[H3|T]], X).
hapus([H1|[H2|T]], X) :- H1=:=H2, hapus(T, X).
:- program.

% 1 1 2 3 4 5
% 1 1 1 2 3 4 5
% 1 1 1 1 1
