#algortimo que valida uma data por exemplo 01/18 não é valido somente 01/10/2018

data = input("Digite a data para validar: ")
mes = 1
validada = False
nao_validada = True
"""
    data = 1/10/2018
    devemos validar o formato da data, como não temos o zero na frente do valor  devemos fazer uma cocatenação
"""
#parte que valida e concatena
for i in range(1, 32):#primeiro a gente trava o mes e o ano
    for j in range(1, 32): #agora a gente anda os dias e os anos
        while(mes <= 12):
            if(mes < 10):
              mes_valido = '0' + str(mes)
            else:
              mes_valido = str(mes)
          #parte que controla o dia
            if(j < 10):
             dia_valido = '0' + str(j)
            else:
                dia_valido = str(j)
            #parte que controla o mes eo ano
            if(i < 10):
                ano_valido = '200' + str(i)
            else:
                if (i >= 10):
                 ano_valido = '20' + str(i)

            data_valida = dia_valido + '/' + mes_valido + '/' + ano_valido
            if(data == data_valida ):
                print("Data informada é valida!")
                validada = True
                break
            else:
               nao_validada = False
            mes = mes + 1
        mes = 1
#end_for
if(validada == False and nao_validada == False):
    print("A data informada é invalida!")
