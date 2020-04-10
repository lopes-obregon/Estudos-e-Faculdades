#algortimo que calcula a divisão de um numero e imprime o inteiro e o float
num1 = float(input("Digite o primeiro valor: "))
num2 = float(input("Digite o segundo valor: "))
resultado_float = num1 / num2
resultado_int = int(num1 / num2)
print("resultado em float: %.0f" %resultado_float)
print("Resultado em int: ", resultado_int)