#coding: utf-8
#sistemas de classe
__author__ = 'Renan Lopes Obregon'
class Calculadora:
    def __init__(self, parm1, param2):
        self.a = parm1
        self.b = param2
    def soma(self):
        return self.a + self.b
    def subtracao (self):
        return self.a - self.b
    def multiplicacao (self):
        return self.a * self.b
    def divisao (self, a,b ):
        return a / b
if __name__ == '__main__':
    c = Calculadora(3,4)
    print(c.soma())
