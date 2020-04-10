#coding:utf-8
#author: Renan Lopes Obregon
#import class
from kivy.app import App
from kivy.uix.label import Label
class MeuProgra(App):

    #metodos
    def build(self):
        return Label()


MeuProgra().run()