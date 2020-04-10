#lê um angulo e imprime o seno cosseno e tangente do angulo
from math import sin
from math import  cos
from math import tan
from math import radians
angulo = int(input('Informe o ângulo: '))
angulo = radians(angulo)
print('seno do ângulo {:.2f}\ncosseno do ângulo {:.2f}\n tangente do ângulo {:.2f}'.format(sin(angulo), cos(angulo), tan(angulo)))