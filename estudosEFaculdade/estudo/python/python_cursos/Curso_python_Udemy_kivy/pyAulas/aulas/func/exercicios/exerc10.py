def func_maior_num(a, b, c):
    if(a > b > c):
        print(a)
    elif(b > a > c):
        print(b)
    else:
        print(c)

lista = list()
for i in range(3):
    valor = int(input("Digite um valor de cada vez: "))
    lista.append(valor)
lista.sort()
func_maior_num(lista[0], lista[1], lista[2])