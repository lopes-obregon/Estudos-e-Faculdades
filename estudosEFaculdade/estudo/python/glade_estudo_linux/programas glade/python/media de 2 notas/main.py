import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class Handler:
    def __init__(self):
        self.n1 = builder.get_object("nota1")
        self.n2 = builder.get_object("nota2")
        self.label = builder.get_object("resultado")

    def onDestroy(self, *args):
        Gtk.main_quit()

    def onButtonPressed(self, button):
        media = (float(self.n1.get_text()) + float(self.n2.get_text()))/2
        self.label.set_text("Á média das duas notas é: " + str(media))
if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("media_duas_notas.glade")
    builder.connect_signals(Handler())

    window = builder.get_object("window1")
    window.show_all()

    Gtk.main()