#programa que calcula o aluguel de carro
km_percorrido = int(input('Km percorrido: '))
dia_alugado = int(input('Informe os dias que serão alugados: '))
km_percorrido *= .15
dia_alugado *= 60
total = km_percorrido + dia_alugado
print('Total a pagar R$: ', total)
