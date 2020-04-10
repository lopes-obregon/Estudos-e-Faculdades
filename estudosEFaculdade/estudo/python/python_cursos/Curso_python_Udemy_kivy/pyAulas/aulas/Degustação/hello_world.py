#coding:utf-8
from kivy.app import  App
from kivy.uix.label import Label
def build():#retornando uma instancia de label
    return Label(text= "Hello World")


hello_world = App()
hello_world.build = build
hello_world.run()