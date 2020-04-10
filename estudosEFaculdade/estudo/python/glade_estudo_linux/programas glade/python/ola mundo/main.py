import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("hello.glade")

    window = builder.get_object("window1")
    window.show_all()

    Gtk.main()