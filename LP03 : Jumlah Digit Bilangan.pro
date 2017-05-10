program :- read(A), jumlah(A,B), write(B), nl.
jumlah(A, A) :- A < 10.
jumlah(A, B) :- A1 is A mod 10, A2 is A // 10, jumlah(A2, B1), B is A1 + B1.
:- program.
