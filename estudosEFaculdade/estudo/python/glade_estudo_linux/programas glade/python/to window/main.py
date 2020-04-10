import gi
gi.require_version("Gtk", "3.0")

from gi.repository import Gtk
class Handler:
    def onDestroy(self, *args):
        Gtk.main_quit()

    def onButtonPressed2(self, button):
        window2 = builder.get_object("window2")
        window2.show_all()

    def onButtonPressed1(self, button):
        pass
if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("window2.glade")
    builder.connect_signals(Handler())

    window1 = builder.get_object("window1")
    window1.show_all()

    Gtk.main()