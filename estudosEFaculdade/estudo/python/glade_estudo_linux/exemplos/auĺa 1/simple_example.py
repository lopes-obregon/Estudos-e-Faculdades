#!/usr/bin/env python
#coding: utf-8
#author: "Renan Lopes Obregon
import gi
#importa a versão para ter a certesa
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk
if (__name__ == "__main__"):
    win = Gtk.Window()#cria uma janela vazia
    win.connect("destroy", Gtk.main_quit)#garante que quando clicado no 'x' feche a janela
    win.show_all()#exibe  a janela
    Gtk.main()#executa o procedimento
