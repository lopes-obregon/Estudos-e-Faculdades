import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class Handler:
    def __init__(self):
        self.altura = builder.get_object("altura")
        self.largura = builder.get_object("largura")
        self.labelResultado = builder.get_object("label")

    def onDestroy(self, *args):
        Gtk.main_quit()

    def onButtonPressed(self, button):
        area = float(self.largura.get_text()) * float(self.altura.get_text())#obtém em metros
        litro = area/2
        self.labelResultado.set_text("gastará {} litros de tinta".format(str(litro)))

if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("area_parede_litro.glade")
    builder.connect_signals(Handler())

    window = builder.get_object("window1")
    window.show_all()

    Gtk.main()