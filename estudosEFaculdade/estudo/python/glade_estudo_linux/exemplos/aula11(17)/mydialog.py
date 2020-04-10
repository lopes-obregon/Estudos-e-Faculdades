import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class DialogExample(Gtk.Dialog):
    def __init__(self, parent):
        Gtk.Dialog.__init__(self, "MY Dialog", parent, 0, (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL, Gtk.STOCK_OK),)

    class DialogWindow(Gtk.Window):
        def __init__(self):
            Gtk.Window.__init__(self, title="Dialog Example")
            self.set_border_width(6)

            button = Gtk.Button("Open dialog")
            button.connect("clicked", self.on_button_clicked)

            self.add(button)

        def on_button_clicked(self, widget):
            dialog = DialogExample(self)
            response = dialog.run()

            if(response == Gtk.ResponseType.OK):
                print("The ok button was clicked")

            elif(response == Gtk.ResponseType.CANCEL):
                print("The Cancel button was clicked")

            dialog.destroy()
    if __name__ == '__main__':
        win = DialogWindow()
        win.connect("destroy", Gtk.main_quit)
        win.show_all()
        Gtk.main()