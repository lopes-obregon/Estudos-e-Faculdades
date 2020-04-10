#coding: utf-8
__author__ = "Renan Lopes Obregon"

class Retangulo:

    def area(self):
        return self.l * self.a

    # construct
    def __init__(self, largura, altura):
         self.a = altura
         self.l = largura

r = Retangulo(7, 5)
r.l = "teste"
print(r.area())