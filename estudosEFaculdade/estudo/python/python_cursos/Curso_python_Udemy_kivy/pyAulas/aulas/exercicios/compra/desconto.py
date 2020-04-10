#programa que solicita o valor da compra e aplica 10% de desconto e depois imprime o valor e o valor com o desconto aplicado
valor_atual = float(input("Digite o valor atual da compra: "))
resultado_atual_desc = valor_atual * 0.1
valor_desconto =  valor_atual - resultado_atual_desc
print("O valor Atual é %.2f " %valor_atual)
print("O valor com desconto é: %.2f" %valor_desconto)