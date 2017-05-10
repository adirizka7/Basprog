program :- read(List), cari(List, A), write(A), nl.
cari([], []) :- !.
cari([A], [A]) :- !.
cari([A|[_|T]], [A|X]) :- cari(T, X).
:- program.
