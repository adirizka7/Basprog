program :- read(A), read(B), read(C), jumlah(A,B,C,D), write(D), nl.
jumlah(A, B, C, X) :- C=\=0 , X is A+B+C.
jumlah(A, B, C, X) :- X is A*B.
:- program.
