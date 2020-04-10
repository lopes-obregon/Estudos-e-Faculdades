import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk, GLib
class EntryWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title='Entry Demo')#nome da janela
        self.set_size_request(200, 100)

        self.timeout_id = None

        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.add(vbox)

        self.entry = Gtk.Entry()
        self.entry.set_text("hello World")
        vbox.pack_start(self.entry, True, True, 0)

        hbox = Gtk.Box(spacing=6)
        vbox.pack_start(hbox, True, True, 0)

        self.check_editable = Gtk.CheckButton('editar')
        self.check_editable.connect('toggled', self.on_editable_toggled)
        self.check_editable.set_active(True)
        hbox.pack_start(self.check_editable, True, True, 0)

        self.check_visible = Gtk.CheckButton('visivel')
        self.check_visible.connect('toggled', self.on_visible_toggled)
        self.check_visible.set_active(True)
        hbox.pack_start(self.check_visible, True, True, 0)

        self.pulse = Gtk.CheckButton('Pulse')
        self.pulse.connect('toggled', self.on_pulse_toggled)
        hbox.pack_start(self.pulse, True, True, 0)

        self.icon = Gtk.CheckButton('Icon')
        self.icon.connect('toggled', self.on_icon_toggled)
        self.icon.set_active(False)
        hbox.pack_start(self.icon, True, True, 0)
    def on_editable_toggled(self, button):
        value = button.get_active()
        self.entry.set_editable(value)
    def on_visible_toggled(self, button):
        value = button.get_active()
        self.entry.set_visibility(value)
    def on_pulse_toggled(self, button):
        if(button.get_active()):
            self.entry.set_progress_pulse_step(0.2)
            #chama self.do_pulse  a cada 100 ms
            self.timeout_id = GLib.timeout_add(100, self.do_pulse, None)
        else:
            #Não chama mais a self.do_pulse
            GLib.source_remove(self.timeout_id)
            self.timeout_id = None
            self.entry.set_progress_pulse_step(0)
    def do_pulse(self, user_data):
        self.entry.progress_pulse()
        return True
    def on_icon_toggled(self, button):
        if(button.get_active()):
            icon_name = 'system-search-symbolic'
        else:
            icon_name = None
            self.entry.set_icon_from_icon_name(Gtk.EntryIconAccessible.PRIMARY, icon_name)

if __name__ == '__main__':
    win = EntryWindow()
    win.connect('destroy', Gtk.main_quit)
    win.show_all()
    Gtk.main()