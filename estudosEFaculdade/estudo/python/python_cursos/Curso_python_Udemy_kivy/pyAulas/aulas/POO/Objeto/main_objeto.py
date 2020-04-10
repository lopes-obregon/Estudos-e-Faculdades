#coding: utf-8
__author__ = "Renan Lopes Obregon"

class MinhaClasse:
    menbro_cls = 60
    def __init__(self):
        self.menbro_inst = -10
    def func(self):
        print(self.menbro_cls)#instancia
        print(self.menbro_inst)
        print(MinhaClasse.menbro_cls)#objeto

i1 = MinhaClasse()
i2 = MinhaClasse()
print(MinhaClasse.menbro_cls)
print(i1.menbro_cls)
print(i2.menbro_cls)


i1.menbro_cls = 1000
print("--------------")
print(MinhaClasse.menbro_cls)
print(i1.menbro_cls)
print(i2.menbro_cls)

# i1.menbro_inst = 10
# print("i1: " + str(i1.menbro_inst))
# print("i2: " + str(i2.menbro_inst))
#
# MinhaClasse.menbro_cls = 20
# print("---------------------")
# print("i1: " + str(i1.menbro_inst))
# print("i2: " + str(i2.menbro_inst))