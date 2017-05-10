program :- read(A), B is A-1, prime(A, B, C), write(C), nl.
prime(A, B, 0) :- A =:= 1, !.
prime(A, B, 1) :- B =:= 1, !.
prime(A, B, 1) :- A mod B =\= 0, D is B-1, prime(A, D, 1), !.
prime(A, B, 0) :- !.
:- program.
