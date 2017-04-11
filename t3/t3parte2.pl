% Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a
% soma dos quadrados de X e Y.
somaQuad(X,Y,Q) :-
    Q is X*X+Y*Y.

% Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista
% que inicia com o número 0 (zero).
zeroInit(L) :-
    [Y|_] = L,
    Y = 0.

% Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas
% L1 e L2 possuírem o mesmo primeiro elemento.
hasEqHeads(L1,L2) :-
    [X|_] = L1,
    [Y|_] = L2,
    X =:= Y.

% Defina um predicado has5(L) que seja verdadeiro se L for uma lista de
% 5 elementos. Lembre de como funciona a unificação em Prolog e resolva
% este exercício sem usar o predicado pré-definido length.
has5(L) :-
    L = [_,_,_,_,_].

% Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista
% de N elementos. Agora você pode usar um predicado pré-definido.
hasN(L,N) :-
    length(L,N).

% Defina um predicado isBin(L) que seja verdadeiro se L for uma lista
% contendo somente elementos 0 e 1. Use recursão.
isBin([1]).
isBin([0]).
isBin(L) :-
    [H|T] = L,
    (H = 0;
    H = 1),
    isBin(T).

% Defina um predicado mesmaPosicao(A,L1,L2) para verificar se um
% elemento A está na mesma posição nas listas L1 e L2. Assuma que L1 e
% L2 sejam permutações de uma lista de elementos distintos, sem
% repetições. Dica: procure auxílio em predicados pré-definidos.
mesmaPosicao(A,L1,L2) :-
    [A|_] = L1,
    [A|_] = L2.
mesmaPosicao(A,L1,L2) :-
    [_|N1] = L1,
    [_|N2] = L2,
    mesmaPosicao(A,N1,N2).

% Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for
% composta por exatamente 5 repetições do elemento E. Não use recursão.
repete5(E,L) :-
    L = [E,E,E,E,E].

% Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S
% for o somatório dos quadrados dos elementos da lista L.
sumQuads([],0).
sumQuads(L,S) :-
    [H|T] = L,
    sumQuads(T,So),
    S is So+H*H.

% Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a
% lista L for composta por exatamente N repetições do elemento E.
repete(0,_,[]).
repete(N,E,L) :-
    [H|T] = L,
    H == E,
    M is (N-1),
    length(L,N),
    repete(M,E,T).

% Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a
% lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x
% da lista L1.
mapop([],[]).
mapop(L1,L2) :-
    [H1|T1] = L1,
    [H2|T2] = L2,
    H2 is 2*H1+1,
    mapop(T1,T2).

% Defina um predicado positivos(L1,L2), de forma que L2 seja uma lista
% só com os elementos positivos de L1.
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

