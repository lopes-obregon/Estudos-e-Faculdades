#valide o valor do mes e conforme informado deve dizer qual mes se refere
num_mes = int(input("Digite o número do mes para descobrir a qual se refere: "))
if(num_mes <= 0 or num_mes > 12):
    print("valor do mes invalido!")
else:
    if(num_mes == 1):
        print("O mes é Janiero!")
    elif(num_mes == 2):
        print("O mes é Fevereiro!")
    elif(num_mes == 3):
        print("O mes é Março!")
    elif(num_mes == 4):
        print("O mes é Abril!")
    elif(num_mes == 5):
        print("O mes é Maio!")
    elif(num_mes == 6):
        print("O mes é Junho!")
    elif(num_mes == 7):
        print("O mes é Julho!")
    elif(num_mes == 8):
        print("O mes é Agosto!")
    elif(num_mes == 9):
        print("O mes é Setembro!")
    elif(num_mes == 10):
        print("O mes é Outubro!")
    elif(num_mes == 11):
        print("O mes é Novembro!")
    elif(num_mes == 12):
        print("O mes é Dezembro!")