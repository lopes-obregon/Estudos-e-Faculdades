#coding: utf-8
__author__ = "Renan lopes Obregon"
#teste de classe e metodos
class Pessoa:
    #construtor
    #metodo inicializador / é chamado quando  um metodo é instanciado pelomenos uma vez
    def __init__(self, nome):
        self.nome = nome
    def __str__(self):
        return self.nome
if __name__ == "__main__":
    regis = Pessoa('Regis')
    print(regis)
    fabio = Pessoa('fabio')
    print(fabio)