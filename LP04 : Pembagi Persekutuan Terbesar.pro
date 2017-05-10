program:-read(A), read(B), gcd(A,B), nl.
gcd(A,B):-B==0, write(A).
gcd(A,B):-B=\=0, X is A mod B, gcd(B,X).
:- program.
