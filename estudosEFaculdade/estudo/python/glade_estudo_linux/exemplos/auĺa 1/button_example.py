#Python: 3x
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk
#classe do programa
class MyWindow(Gtk.Window):
    def __init__(self):#construtor da classe
        Gtk.Window.__init__(self, title="Hello world")#chamada do construtor da super classe
        #as proximas tres linhas são para criação do programa
        self.button = Gtk.Button(label="CLick Aqui")#define o nome do botão
        self.button.connect("clicked", self.on_button_clicked)#conecta ao sinal de cliclado e adiciona como filho a janela superior
        self.add(self.button)#adiciona a janela
        #s for clicado chama o metodo
    def on_button_clicked(self, widget):
        print("Hello World")

if(__name__ == '__main__'):
    win = MyWindow()
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    Gtk.main()