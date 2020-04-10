import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class SpinnerAnimation(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="Spinner")#define o nome da janela
        self.set_border_width(3)#seta o tamanho da borda
        self.connect("destroy", Gtk.main_quit)#define para fechar a janela

        #cria o botão
        self.button = Gtk.ToggleButton("Iniciando o spinning")
        self.button.connect("toggled", self.on_button_toggled)
        self.button.set_active(False)

        self.spinner = Gtk.Spinner()
        #cria o spinner
        self.table = Gtk.Table(3, 2, True)
        self.table.attach(self.button, 0, 2, 0, 1)
        self.table.attach(self.spinner, 0, 2, 2, 3)

        self.add(self.table)
        self.show_all()

    def on_button_toggled(self, button):
        if button.get_active():
            self.spinner.start()
            self.button.set_label("Stop Spinning")
        else:
            self.spinner.stop()
            self.button.set_label("Start Spinning")

myspinner = SpinnerAnimation()
Gtk.main()