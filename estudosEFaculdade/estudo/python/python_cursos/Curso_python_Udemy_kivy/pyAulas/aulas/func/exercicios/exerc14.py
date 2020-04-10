#fatorial
def func(*args):
    resultado = 1
    valor = args[0]
    if(valor > 0):
        for i in range(args[0]):
            resultado *= valor
            valor -=1
        print(resultado)
    elif(valor == 0):
        print("1")
    else:
        print("Informe numéros positivos")
func(5)