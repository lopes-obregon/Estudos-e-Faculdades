import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

class MyWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title='Hello World')
        #primeiro criamos um contêiner de caix horizontalmente. onde 6 pizels são
        #colocados ente os filhos
        self.box = Gtk.Box(spacing=6)
        self.add(self.box)#esta caixa se torna o filho da janela de nível superior
        #logo depois adicionamos dois botões diferentes ao contêiner da caixa
        self.button1 = Gtk.Button(label='Hello')
        self.button1.connect('clicked', self.on_button1_clicked)
        self.box.pack_start(self.button1, True, True, 0)#com o comando pax_start() poscisiona da esquerda para a direita

        self.button2 = Gtk.Button(label='Goodbye')
        self.button2.connect('clicked', self.on_button2_clicked)
        self.box.pack_start(self.button2, True, True, 0)

    def on_button1_clicked(self, widget):
        print("Hello")
    def on_button2_clicked(self, widget):
        print("Goodbye")

if __name__ == '__main__':
    win = MyWindow()
    win.connect('destroy', Gtk.main_quit)
    win.show_all()
    Gtk.main()