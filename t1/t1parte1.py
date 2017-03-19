#Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.
def somaQuad(x,y): return pow(x,2)+pow(y,2)

#Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2): return l1[0]==l2[0]

#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome. Defina uma função auxiliar para ajudar neste exercício.
def addSr(str): return 'Sr'+str
list(map(addSr,['Rafael','Gabriel','Guilherme']))

#Crie uma função que receba uma string e retorne o número de espaços nela contidos. Defina uma função auxiliar para ajudar neste exercício.
def checkSpace(x): return x==' '
len(list(filter(checkSpace,'Gosto de programar')))

#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista. Defina uma função auxiliar para ajudar neste exercício.
def calc(n): return 3*n*2+2/n+1
list(map(calc,[1,2,3]))

#Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos. Defina uma função auxiliar para ajudar neste exercício.
def negativo(x): return x<0
list(filter(negativo,[1,-3,7,-5,2,-10]))

#Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive. Defina uma função auxiliar para ajudar neste exercício.
def zeroToHundred(x): return x>0 and x<100
list(filter(zeroToHundred,[-5,10,68,207,102,50]))

#Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares. Defina uma função auxiliar para ajudar neste exercício.
def evenNum(x): return x%2 == 0
list(filter(evenNum,[1,2,10,7,8,13]))

#Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False.
#Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.
def charFound(c,s): return s.count(c)>0

#Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string.
def addMarc(x): return '<B>'+x+'</B>'
list(map(addMarc,['eu','gosto','de','programar']))
