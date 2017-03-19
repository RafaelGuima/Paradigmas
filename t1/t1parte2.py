#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
list(map(lambda x:'Sr '+x,['Rafael','Gabriel','Guilherme']))

#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
list(map(lambda n:3*n*2+2/n+1,[2,7,5,14,9]))

#Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
list(filter(lambda x:x[-1]=='a',['Rafa','Gabriel','Luiza','Marcelo']))

#Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970.
#Para testar a condição, sua função deverá subtrair a idade do ano atual.
list(filter(lambda x:2017-x>1970,[20,30,51,57]))

#O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.
numbers = [1,2,3,4]
new_numbers = list(map(lambda x:x*2,numbers))
print(new_numbers)
