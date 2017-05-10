program :- read(A), read(List), jumlah(A,List,N), write(N), nl.
jumlah(A,[],0) :- !.
jumlah(A,[H|T],X) :- H mod A =:= 0, jumlah(A,T,Y), X is Y+1.
jumlah(A,[H|T],X) :- jumlah(A,T,X).
:- program.
