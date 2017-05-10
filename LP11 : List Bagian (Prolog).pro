program :- read(A), B is 1,faktor(A, B, Z), write(Z), nl.
faktor(A, B, []) :- A =:= B, !.
faktor(A, B, [B|X]) :-
    (A mod B) =:= 0,
    C is B+1,
    faktor(A, C, X).
faktor(A, B, X) :-
    C is B+1,
    faktor(A, C, X).
:- program.
