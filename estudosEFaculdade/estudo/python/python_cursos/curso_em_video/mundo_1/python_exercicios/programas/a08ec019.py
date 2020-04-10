#programa que lê o nome dos alunos  sorteia e escreve o nome do aluno escolido
import random
aluno1 = input('digite o primeiro aluno: ')
aluno2 = input('Digite o segundo aluno: ')
aluno3 = input('Digite o terceiro aluno: ')
aluno4= input('Digite o quarto aluno: ')
lista = [aluno1, aluno2, aluno3, aluno4]
escolhido = random.choice(lista)
print('O aluno escolhido foi: ', escolhido)