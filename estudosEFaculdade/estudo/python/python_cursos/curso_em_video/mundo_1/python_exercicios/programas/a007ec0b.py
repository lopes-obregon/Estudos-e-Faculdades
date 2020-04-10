#programa que lê largura e altura de uma parede em metros e calcula a área e a quantidade de tinta necessária para pintá-la, sabendo que cada litro de tinta pinta uma área de 2m^2
largura = float(input('largura: '))
altura = float(input('altura: '))
area = largura * altura #obtém em metros quadrados
litro = area/2
print('gastará {:.3f} litros de tinta'.format(litro))
