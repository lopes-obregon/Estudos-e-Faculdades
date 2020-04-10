#coding: utf-8
#author: Renan Lopes Obregon

try:
    a = 10 / 0
    print(a)
except ZeroDivisionError:
    print("Não é possível dividir um número por zero.")
