#coding:utf-8
__author__ = "Renan Lopes Obregon"
#importações das calsses
from kivy.app import App
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.core.window import Window
#metodos
def click():
    print(ed.text)

def build():
    layout = FloatLayout()
    #texto
    global ed
    ed = TextInput(text="eXcript")
    ed.size_hint = None, None #resetando os parametros
    ed.height = 300 #height 300px
    ed.width = 400 #widht 400 px
    ed.y = 250 #distancia do topo do video
    ed.x = 60
   #botão
    bt = Button(text="Clique aqui")
    bt.size_hint = None, None
    bt.height = 50
    bt.width = 200
    bt.y = 100
    bt.x = 200
    bt.on_press = click
    #adiciona os botoes e textos os layout
    layout.add_widget(ed)
    layout.add_widget(bt)


    return layout

#main
janela = App()#associa nova instancia de App
janela.title = "eXcript" #altera o nome do programa
Window.size = 600, 600 #tamanho da janela


janela.build = build #associa a função build para a função build assima
janela.run()
