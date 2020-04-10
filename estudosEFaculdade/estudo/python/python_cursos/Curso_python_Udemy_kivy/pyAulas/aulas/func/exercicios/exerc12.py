#multiplica todos os valores da lista
def func(*args):
    resultado = 1
    for i in range(len(args)):
        resultado *= args[i]

    print(resultado)

func(1,2,3,4,5)