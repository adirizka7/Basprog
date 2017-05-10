program :- read(List), selisih(List, B), write(B), nl.
selisih([], []) :- !.
selisih([A], []) :- !.
selisih([H1|[H2|T]], [C|X]) :- H1>=H2, C is H1-H2, selisih([H2|T], X).
selisih([H1|[H2|T]], [C|X]) :- C is H2-H1, selisih([H2|T], X).
:- program.
