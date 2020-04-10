#programa que lê um número e mostra se é maior ou menor
num = int(input("Digite um número: "))
num2 = int(input("Digite o segundo número: "))
if (num > num2):
    print("%i é maior que %i" %(num, num2))
elif(num < num2):
    print("%i é maior que %i" %(num2, num))
elif(num == num2):
    print("Os números são iguais")