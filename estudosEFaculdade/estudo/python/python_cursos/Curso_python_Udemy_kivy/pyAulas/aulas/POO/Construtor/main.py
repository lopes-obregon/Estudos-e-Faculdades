#coding: utf-8
__author__ = "Renan Lopes Obregon"

def teste(s):
    print(id(s))

class A:
    def __int__(self):#construtor
        print(id(self))

a = A()
print(id(a))
teste(a)