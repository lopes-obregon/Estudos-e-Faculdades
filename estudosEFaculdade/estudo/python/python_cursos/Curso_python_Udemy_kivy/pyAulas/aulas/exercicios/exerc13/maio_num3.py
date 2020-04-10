#lê 3 valores e mostra qual é maior entre eles
num1 = int(input("Digite o primeiro númro: "))
num2 = int(input("Digite o segundo número: "))
num3 = int(input("Digite o terceiro número: "))

if(num1 > num2 > num3):
    print(num1)
elif(num2 > num1 > num3):
    print(num2)
else:
    print(num3)