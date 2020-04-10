def func():
    print(dic)

n = 0
dic = dict ()
while(n != -1):
    valor = int(input("Digite o valor: "))
    if valor != -1:
        dic[n] = valor
    else:
        break
    n += 1
func()
