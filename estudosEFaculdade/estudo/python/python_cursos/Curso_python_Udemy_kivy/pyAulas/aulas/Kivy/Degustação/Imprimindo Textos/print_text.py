#coding:utf-8
#kivy linguaguem de marcação e não de programação
from kivy.app import App
from kivy.uix.label import Label


def build():#constroi o texto
    lb = Label()
    #formatação de texto
    lb.text = "Curso de Python e Kivy"
    lb.italic=True
    lb.font_size=50
    return lb
    #return Label(texte="Curso de Python e Kivy", italic=True, font_size=50)


app = App()
app.build = build
app.run()

