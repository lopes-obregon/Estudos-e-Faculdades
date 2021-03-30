#codifica a entrada
codigo = ''
decodifica = ''
#codifica o dado
def codifica(codigo):
    aux = 1
    i = 0
    while i < len(codigo):
        if(i+1 >= len(codigo)):
            decodifica = decodifica + str(aux) + codigo[i]
        elif(codigo[i] == codigo[i+1]):
            aux += 1
        elif(codigo[i] != codigo[i+1]):
            decodifica = decodifica + str(aux) + codigo[i]
            aux = 1

        i = i + 1
    f = open("data", 'w')
    f.writelines(decodifica)
    f.close()
    print("Dado codificado", decodifica)

def decodificaEntrada(codigo):
    i = 0
    aux = 0
    while i < len(codigo):
        for j in range(0, 10):
            if codigo[i] == str(j):
                aux = int(codigo[i])
                n = 0
                while n < aux:
                    decodifica = decodifica + codigo[i+1]
                    n +=1
        i +=1
    f = open("data", 'w')
    f.writelines(decodifica)
    f.close()
    print("Dado decodificado", decodifica)
if __name__ == "__main__":
    for line in f:
        codigo = line
    print(codigo)
