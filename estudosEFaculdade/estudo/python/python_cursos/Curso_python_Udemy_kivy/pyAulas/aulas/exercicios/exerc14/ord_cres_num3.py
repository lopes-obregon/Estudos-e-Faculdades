#programa que imprime em ordem crescente os números
num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))
num3 = int(input("Digite o terceiro número: "))

if(num1 > num2 > num3):
    a = num1
    if(num2 > num3):
        a = a, num2 , num3
    else:
        a = a, num3, num2
    print(a)
elif(num2 > num1 > num3):
   a = num2
   if(num1 > num3):
       a = a, num1, num3
   else:
       a = a, num3, num1

    print(a)
else:
    a = num3
    if(num1 > num2):
        a = a, num1, num2
    else:
        a = a, num2, num1

    print(a)