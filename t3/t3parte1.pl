pai(roberto,joao).
pai(joao,jose).
pai(roberto,julio).
pai(julio,marcos).
pai(julio,mario).
avo(X,Z) :- pai(X,Y), pai(Y,Z).
% ?- avo(joao,Y).
%  Call: (8) avo(joao, _980) ? creep   % avo chama pai e troca Y
%  Call: (9) pai(joao, _1198) ? creep  % verifica se joao tem par
%  Exit: (9) pai(joao, jose) ? creep   % acha par para joao e retorna
%  Call: (9) pai(jose, _980) ? creep   % verifica se jose tem par
%  Fail: (9) pai(jose, _980) ? creep   % nao acha par para jose
%  Fail: (8) avo(joao, _980) ? creep   % avo falha e retorna falso
% False
