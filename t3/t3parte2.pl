somaQuad(X,Y,Q) :-
    Q is X*X+Y*Y.

zeroInit(L) :-
    [Y|_] = L,
    Y = 0.

hasEqHeads(L1,L2) :-
    [X|_] = L1,
    [Y|_] = L2,
    X =:= Y.

has5(L) :-
    L = [_,_,_,_,_].

hasN(L,N) :-
    length(L,N).

isBin([1]).
isBin([0]).
isBin(L) :-
    [H|T] = L,
    (H = 0;
    H = 1),
    isBin(T).

mesmaPosicao(A,L1,L2) :-
    [A|_] = L1,
    [A|_] = L2.
mesmaPosicao(A,L1,L2) :-
    [_|N1] = L1,
    [_|N2] = L2,
    mesmaPosicao(A,N1,N2).

repete5(E,L) :-
    L = [E,E,E,E,E].

sumQuads([],0).
sumQuads(L,S) :-
    [H|T] = L,
    sumQuads(T,So),
    S is So+H*H.

repete(0,_,[]).
repete(N,E,L) :-
    [H|T] = L,
    H == E,
    M is (N-1),
    length(L,N),
    repete(M,E,T).

mapop([],[]).
mapop(L1,L2) :-
    [H1|T1] = L1,
    [H2|T2] = L2,
    H2 is 2*H1+1,
    mapop(T1,T2).

positivos([],_).
positivos(L1,L2) :-
    [H1|T1] = L1,
    H1 > 0,
    [H2|T2] = L2,
    H2 = H1,
    positivos(T1,T2).
positivos(L1,L2) :-
    [_|T1] = L1,
    positivos(T1,L2).

