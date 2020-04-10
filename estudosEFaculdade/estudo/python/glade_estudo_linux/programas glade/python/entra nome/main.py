import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class Handler:
    def onDestroy(self, *args):
        Gtk.main_quit()
    def onButtonPressed(self, button):
        en = builder.get_object("entrada_de_dados")
        label = builder.get_object("texto")
        palavra_nome ="Olá, "  + en.get_text()
        label.set_text(palavra_nome)
if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("entra_nome.glade")
    builder.connect_signals(Handler())
    #entra_dado = builder.get_object("entrada_de_dados")
    #print("entrada dos dados é: ", entra_dado)
    window = builder.get_object("window1")
    window.show_all()

    Gtk.main()