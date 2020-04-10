import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

#classes
class ToglleButtonWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="ToggleButton Demo")#define o nome da janela ou programa
        self.set_border_width(10) #define o tamanho das bordas

        hbox = Gtk.Box(spacing=6)#define o tamanho da caixa no caso o espaço
        self.add(hbox)

        button = Gtk.ToggleButton("Button 1")
        button.connect("toggled", self.on_button_toggled, "1")
        hbox.pack_start(button, True, True, 0)

        button = Gtk.ToggleButton("B_utton 2", use_underline=True)
        button.set_active(True)
        button.connect("toggled", self.on_button_toggled, "2")
        hbox.pack_start(button, True, True, 0)

    def on_button_toggled(self, button, name):
        if(button.get_active()):
            state = "on"
        else:
            state = "off"
        print("Button", name, "was turned", state)

if __name__ == '__main__':
    win = ToglleButtonWindow()
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    Gtk.main()