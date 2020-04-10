#usuario define o intervalo dos numeros primos
vezes_dividida = 0#zero será o elemento neutro pos não existe primo de zero
num_pri = 0
valor_inicial = int(input("Digite o intervalo inicial: "))
valor_final = int(input("Digite o intervalo final: "))
valor_final += 1
if(valor_inicial == 0):
    valor_inicial = 1
for i in range(valor_inicial, valor_final):
    for j in range(valor_inicial, valor_final):
        if(i % 1 == 0 and i % j == 0):# os que são primos se repetem duas vezes
            vezes_dividida += 1
    if (vezes_dividida == 2 ):
        print(i)
        vezes_dividida = 0
    elif(vezes_dividida >= 3):
        vezes_dividida = 0