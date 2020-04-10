#programa que imprime os numeros num intervalo pré-definido pelo usuario
valor_ini = int(input("Digite o valor inicial do intervalo: "))
valor_final = int(input("Digite o valo final do intervalo: "))
valor_final += 1
for i in range(valor_ini, valor_final):
    print(i)