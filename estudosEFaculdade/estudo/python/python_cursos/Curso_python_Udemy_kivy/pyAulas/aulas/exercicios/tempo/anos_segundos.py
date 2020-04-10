#pessa ao usuario para digitar dias horas minutos e segundos e converte tudo para segundos
dia = int(input("Digite a quantidade de dias: "))
horas = int((input("Digite a quantidade de horas: ")))
minutos = int(input("Dihite a quantidade de minutos: "))
segundos = int(input("Digite a quantidade de segundos: "))
"""
 1 minuto = 60 segundos
 2 minutos = 120 segundos

 """
#parte que converte os minutos em segundos
convert_minutos_segundos = minutos * 60
#parte que converte horas em segundos
convert_horas_segundos =  horas * 3600
#parte que converte dias em segundos
convert_dias_segundos = dia * 86400

#parte que soma todo o valor convertido
result_convertido = convert_dias_segundos + convert_horas_segundos + convert_minutos_segundos
result_convertido = result_convertido + segundos
print("O total em segundos é: ", result_convertido)