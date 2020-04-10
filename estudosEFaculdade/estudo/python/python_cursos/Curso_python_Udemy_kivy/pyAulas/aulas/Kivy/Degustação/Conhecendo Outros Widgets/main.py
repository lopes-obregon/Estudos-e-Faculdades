#coding:utf-8
#author: Renan Lopes Obregon
from kivy.app import App
from kivy.uix.button import Button
#codigo com os botões
class Janela (App):
    def click(self):
        print("O botão foi clicado")


    def build(self):
        #criando instancia de button
        bt = Button(text="Clique aqui")
        bt.on_press = click #associa o nome de on_press da biblioteca
        return bt

Janela().run()