#programa que o cateto oposto e o adjacente de um triangulo retangolo  calcule e mostre  o comprimento da hipotenusa
from math import hypot
co = float(input('cateto oposto: '))
cd = float(input('cateto adjacente: '))
print(hypot(co,cd))
