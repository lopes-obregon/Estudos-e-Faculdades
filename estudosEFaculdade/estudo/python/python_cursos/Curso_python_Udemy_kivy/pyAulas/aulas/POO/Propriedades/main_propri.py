    #coding: utf-8
__author__ = "Renan Lopes Obregon"

class A:
    def __init__(self):
        self._var = 0
    @property #decoreitor
    def var(self):#get
        print("valor está lindo lido")
        return self._var
    @var.setter#decoreitor
    #set
    def var(self, x):
        print("Valor está sendo escrito")
        self._var = x


    #var = property(fget=_get_var, fset=_set_var)
#main
a = A()
a.var = 10

t = a.var



