#programa que imprime os numeros primos de 0 a 100
vezes_dividida = 0#zero será o elemento neutro pos não existe primo de zero
num_pri = 0
for i in range(1, 101):
    for j in range(1, 101):
        if(i % 1 == 0 and i % j == 0):# os que são primos se repetem duas vezes
            vezes_dividida += 1
    if (vezes_dividida == 2 ):
        print(i)
        vezes_dividida = 0
    elif(vezes_dividida >= 3):
        vezes_dividida = 0