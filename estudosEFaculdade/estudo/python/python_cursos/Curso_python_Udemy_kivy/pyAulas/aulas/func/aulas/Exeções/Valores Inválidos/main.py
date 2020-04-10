#coding: utf-8
#author:  Renan Lopes Obregon
def input_float(msg):
    while True:
        try:
            return  float(input(msg))

        except ValueError:
            print("Número inválido")
#main()
num1 = input_float("Digite o primeiro numero: ")
num2 = input_float("Digite o Segundo número: ")
try:

    print(num1 / num2)
except ZeroDivisionError:
    print("Não é possível dividir um número por zero.")
