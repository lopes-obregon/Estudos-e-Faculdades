def func(a, b, c):
    print(a)
    print(b)
    print(c)
    lista.sort()#organiza em ordem crescente
    resultado = 0
    for i in range(len(lista)):
      resultado += lista[i]
    resultado /= len(lista)
    print(resultado)
    print(lista)
lista = [10,9,12]
func(lista[1],lista[0],lista[2])