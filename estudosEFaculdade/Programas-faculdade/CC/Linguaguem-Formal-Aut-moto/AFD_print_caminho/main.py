#!/usr/bin/env python
#athor : "Renan Lopes Obregon"
#programa que verifica se a palavra é valida ou não
#função que entra com os dados
def entrada_de_dados():
    a = input().split(',')
    return a
#função que compara 
def enum_estado_saida(saida, estado):
    # o estado é uma lista de caracteres
    for i in range(0, len(estado)):
        if(saida == estado[i]):
            return i
def enum_incial_estado(estado,inicial):
    '''
    sendo os estados de A,..,Z
    temos os numeros conforme as entradas
    E0 == 0, E1 == 1, E2 == 2, E3 == 3, E4 == 4 , ..., En == n

    '''
    #compara o estado com o inicial
    for i in range(0, len(inicial)):
        for j in range(0, len(estado)):
            if(estado[j] == inicial[i]):
                return i
#função que retorna o indicie
def return_indicie(palavra,indice_for):
    aux = palavra[indice_for]
    straux = '0123456789'
    stralfa = 'qwertyuiopasdfghjklçzxcvbnmQWERTYUIOPASDFGHJKLÇZXCVBNM'
    global  existe_como_str_or_int
    existe_como_str_or_int = False
    if(existe_como_str_or_int == False):
        for i in straux:
            if(aux == i):
                aux = int(aux)
                existe_como_str_or_int = True
                break
    elif(existe_como_str_or_int == False):
        for i in stralfa:
            if(aux.find(i) != - 1):
                aux = int(aux.find(i))
                existe_como_str_or_int = True
                break

    return aux
#entrada de palavra
def input_palavra():
    pala = input("Palavra: ")
    return  pala
# #captura do delta
def captura_delta(delta,estado, alfabeto):
    global dado
    for i in range(0, len(estado)):
        delta.append([])
        for j in range(0, len(alfabeto)):
            print("delta(%s , %s)" % (estado[i], alfabeto[j]))
            dado = input()  # variavel para capturar os dados
            #VERIFICA O DADO
            esta = False
            while(esta == False):
                try:
                    estado.index(dado)
                    esta = True
                except ValueError:
                    print("Dado invalido insira um dado valido")
                    dado = input()
            delta[i].append(dado)  # guardando em delta os dados inseriodos na variavel dado
#função que encontra o erro na maquina
def error_automoto(indicie,alfabeto,palavra):
    #veirificar se o indicie ou a cordenada existe no alfabeto
    #retorna veradeiro se a palavra ou coordenada existe no alfabeto
    #coverte a palavra em str
    existe = False
    for i in alfabeto:
        if(palavra[indicie] == i):
            existe = True
            break
    return existe

#main
if(__name__ == "__main__"):
        #entrada dos dados
    ver = False
    verpalavra = 's'#variavel para condição
    verautomoto = 's' #variavel para condição
    global inicial, estado, palavra, delta,alfabeto
    while(ver == False):
        if(verautomoto == 's'):
            print("Estado: ")
            estado = entrada_de_dados()
            print("Finais: ")
            final = entrada_de_dados()
            print("Inicial: ")
            inicial = entrada_de_dados()
            print("Alfabeto: ")
            alfabeto = entrada_de_dados()
            #parte que preenche o alfa
            delta = []#delta atribui uma lista
            captura_delta(delta,estado,alfabeto)
        if(verpalavra == 's'):
            palavra = input_palavra()

        #calcula autômoto
        if(verautomoto != 'n' or verpalavra != 'n'):
            saida = enum_incial_estado(estado, inicial)
            saida_print = inicial[0]
            valid_palavra = True
            for i in range(0, (len(palavra))):  # quantidade de vezes que ira pesquisar
                # a ordem dos estados sempre são as mesmas
                indicie = return_indicie(palavra, i)
                if(error_automoto(indicie,alfabeto,palavra) == False):
                    print("Desculpe mas o autômoto travou, isso ocorre por ter entrada (palavra) invalida. ")
                    valid_palavra = False
                    break
                else:
                    aux = delta[saida][indicie]
                    saida = enum_estado_saida(aux, estado)  # Função esta retornando um valor para o estado
                    saida_print = str(saida_print) + ',' + estado[saida]
            if(valid_palavra == True):
                print(saida_print)
                print("Palavra valida")

        #verifica a palavra
        #devemos andar a palavra
        verpalavra = input("Verificar nova palavra(s/n)? ")
        verautomoto = input("Novo autômoto(s/n) ? ")
        if(verpalavra == 'n' and verautomoto == 'n'):
            ver = True