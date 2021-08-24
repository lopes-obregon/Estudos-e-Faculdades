import os
import time
lista = ['100.d', '100.d', '100.d', '100.d', '500000.d']
#lista = ['100.a', '100.a', '100000000.a']
##procedimento para gerar os numeros
def gerador():
    os.system("gcc gerador.c")
    ##os.system("./a.out 10 d")
    ##os.system("./a.out 1000 d")
    ##os.system("./a.out 10000 d")
    ##os.system("./a.out 100000 d")
    ##os.system("./a.out 500000 d")
    os.system("./a.out 1000000 a")
    os.system("./a.out 10000000 a")
    os.system("./a.out 100000000 a")
    print("Gerados com sucesso!")
    time.sleep(5)
##procedimento para compilar o programa
def programa():
    os.system("gcc main.c")
    for i in lista:
        for j in range(4, 9):
            if(j != 5):
                a = j
                a = str(a)
                c = i + a
                print("rodando ", c)
                b = './a.out '+ a +' '+ i +' saida'+c
                os.system(b)
    print("Ordenado com sucesso!")
    time.sleep(5)
def leitura():
    os.system("gcc leitura.c")
    for i in lista:
        for j in range(4, 9):
            if(j != 5):
                a = './a.out saida' + i + str(j)
                os.system(a)
                time.sleep(5)
    print("Lido com sucesso!")
    time.sleep(10)
def remove():
    for i in lista:
        for j in range(4, 9):
            if(j != 5):
                a = 'rm saida'+ i + str(j)
                os.system(a)
    print("Removido com sucesso!")
    time.sleep(5)
if __name__ == "__main__":
    gerador()
    programa()
    #leitura()
    #remove()