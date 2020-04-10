#coding: utf-8
__author__ = "Renan Lopes Obregon"

from kivy.app import App
from kivy.uix.textinput import TextInput

def build():
    return TextInput(text="Componente TextInput")#retornando uma instancia de input

janela = App()
janela.build = build
janela.run()