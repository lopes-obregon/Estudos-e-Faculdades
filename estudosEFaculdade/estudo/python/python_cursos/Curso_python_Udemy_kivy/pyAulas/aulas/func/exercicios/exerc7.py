def func(*args):
    print(args)

n = 0
l = list()
print("Digite os valores: ")
while(n > -1):
    valor = int(input())
    n = valor
    if(valor != -1):
        l.append(valor)
func(l)