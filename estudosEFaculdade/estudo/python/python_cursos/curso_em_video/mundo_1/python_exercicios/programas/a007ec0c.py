#programa que lê o preço de um produto e mostra o seu novo preço com 5% de desconto
a = float(input('Qual o preço do produto: '))
deconto = a*0.05
resultado = a - deconto
print('preço do produto com 5% de desconto é R$: ', resultado)