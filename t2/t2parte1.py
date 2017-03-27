#Defina uma função addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado.
def addSuffix(suf,nomes): return [x+suf for x in nomes]

#Escreva uma função countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.
def countShorts(words): return len([x for x in words if len(x) < 5])

#Defina uma função stripVowels(s) que receba uma string e retire suas vogais.
def stripVowels(s): return ''.join([x for x in s if x not in 'AaEeIiOoUu'])

#Defina uma função hideChars(s) que receba uma string, possivelmente contendo espaços, e que retorne outra string substituindo os demais caracteres por '-', mas mantendo os espaços.
def hideChars(s): return ''.join(['-' if x!=' ' else ' ' for x in s ])

#Defina uma função que receba um número n e retorne uma tabela de números de 1 a n e seus quadrados, conforme os exemplos abaixo (você vai usar tuplas em Python).
def squareTable(n): return [(x,pow(x,2)) for x in list(range(1, n+1))]

#Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista.
def firstLast(l): return ''.join([x[0] + x[-1] for x in l])

#Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista.
#Não achei solução.

#Escreva uma função enumerate(words) que numere cada palavra da lista recebida.
def enumerate(words):
    return [(words.index(x)+1,x) for x in words]

#Escreva uma função isBin(s) que verifique se a string recebida representa um número binário.
def isBin(s):
    return [x for x in s if x not in '10'] == []

#Exercício 10 é completamente e absolutamente IMPOSSIVEL.
