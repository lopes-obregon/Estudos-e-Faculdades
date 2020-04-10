#coding: utf-8
#receba uma quantidade de numeros, e mostra qual deles é um numero primo
def func(*args):
   aux = 1
   div = 0
   for i in range(len(args)):
       valor = args[i]
       while (aux <= valor):
           if(valor % aux == 0):
              div += 1

           aux += 1

       if(div == 2):
           print("O numéro %d é primo! " %valor)
           div = 0
           aux = 1
       else:
           div = 0
           aux = 1
n = 1
l = list()
print("Digite os valores para serem gravados ou 0 para sair")
while(n >= 1):
    n = int(input())
    if(n > 0):
        l.append(n)
    else:
        func(*l)
        break