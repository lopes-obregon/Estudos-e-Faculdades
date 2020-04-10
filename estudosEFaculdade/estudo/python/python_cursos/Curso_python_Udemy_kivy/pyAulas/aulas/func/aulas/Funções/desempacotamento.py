#coding: utf-8
#desempacotamento 1
def pessoa(nome, sobrenome, idade):
    print(nome)
    print(sobrenome)
    print(idade)

#lista = "eXcript", "Brasil", 20


#pessoa(tupla[0], tupla[1], tupla[2])
#pessoa(*lista)

d= {"nome":"eXcript", "sobrenome":"Brasil", "idade":20}
pessoa(**d)
#-------------- desempacotamento 2 -------------------------#
print("dsempacotamento 2")
lista = [11, 10, 12]
tupla = 11, 10, 12
def func(a, b, c):
    print(a)
    print(b)
    print(c)
    #lista.sort()
    #func(*lista)
#l = [*tupla]#desempactota a tupla
#l.sort()
#func(*l)
func(**dict(zip(("b", "a", "c"),lista)))