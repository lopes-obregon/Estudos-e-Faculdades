#escrever um algoritmo que verifica se um numero esta em um intervalo ou não
def func(inicial,final, numero):
    for i in range(inicial,final):
        if(i == numero):
            print("O numero %d esta nesse intervalo." %numero)
        else:
            print("O numero %d não esta neste intervalo." %numero)
            break
func(0,10,20)