#coding: utf-8
__author__ = "Renan Lopes Obregon"

"""get_ + atributo > get_ + estudo
get_estudo()
set_ + atributo > set_ + estudo


######################
método gettres : sempre retornam valores 
Get significa o retorno de dados
métodos settres : sempre recebem  valores por parâmetros
set significa a atribuição de valor
métodos assessores também garantem a integridade  das informações  internas  ao objetos
"""
class Retangulo:
    def __init__(self, largura, altura):#cinstructor
        self._largura = 0
        self._altura = 0
        self.altura = altura
        self.largura = largura
    @property
    def altura(self):#recebe valor
        return self._altura
    @altura.setter
    def altura(self, num):#recebe valor
        if(not (isinstance(num, int) and (num > 0))):
           raise ValueError("Altura é invalida: {}".format(num))

        self._altura = num
    @property
    def largura(self):
        return self._largura
    @largura.setter
    def largura(self,num):
        if (not(isinstance(num, int) and (num > 0))):
            raise ValueError("Largura é invalida {}".format(num))

        self._largura = num
    @property
    def area(self):#retorna o valor
        return self._altura * self._largura

    # altura = property(fget=_get_altura , fset=_set_altura)
    # largura = property(fget=_get_largura, fset=_set_largura)
    #
    # area = property(fget=_get_area)
r = Retangulo(largura=5, altura=5)#forma associativa
r.largura = 10
r.altura = 15
r.area = 10
print(r.altura)
print(r.altura)
print()
