#coding: utf-8
def func(*args):
    tam_args = args
    lista2 = list()
    valor = 0
    for i in range(tam_args):
        if(args[i] != args[i+1]):
            valor = args[i]
            lista2.append(valor)
    print(lista2)


lista = [1,2,3,3,3,3,4,5]
func(lista)