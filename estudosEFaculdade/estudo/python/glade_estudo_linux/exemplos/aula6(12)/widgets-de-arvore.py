import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk
software_list = [("Firefox", 2002, "C++"),("Eclipse", 2004, "Java"),("Pitivi", 2004, "Python"),("Netbeans", 1996, "Java"),("Chrome", 2008, "C++"), ("Bazaar", 2005, "Python"), ("Git", 2005, "C"), ("Linux Kernel", 1991, "C"), ("GCC", 1987, "C"), ("Frostwire", 2004, "Java")]

class TreeViewFilterWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="Treeview Filter Demo")
        self.set_border_width(10)
        #adiconar elementos e posições
        self.grid = Gtk.Grid()
        self.grid.set_column_homogeneous(True)
        self.grid.set_row_homogeneous(True)
        self.add(self.grid)
        #cria a listStore model
        self.software_listsotre = Gtk.ListStore(str, int, str)
        for software_ref in software_list:
            self.software_listsotre.append(list(software_ref))
        self.current_filter_language= None

        #cria o filtro ...
        self.language_filter = self.software_listsotre.filter_new()
        #seta a função do filtro
        self.language_filter.set_visible_func(self.language_filter_func)

        #cria o treeview ...
        self.treeview = Gtk.TreeView.new_with_model(self.language_filter)
        #cria as colunas com os nome
        for i, column_title in enumerate(
            ["Software", "Release Year", "Programing Language"]
        ):
            renderer = Gtk.CellRendererText()
            column = Gtk.TreeViewColumn(column_title, renderer, text=i)
            self.treeview.append_column(column)

        #cria o butão de filtro para as linguagem, ...
        self.buttons = list()
        for prog_language in ["Java", "C", "C++", "Python", "None"]:
            button = Gtk.Button(prog_language)
            self.buttons.append(button)
            button.connect("clicked", self.on_selection_button_clicked)

        #seta para cima o layout ...

        self.scorllable_treelist = Gtk.ScrolledWindow()
        self.scorllable_treelist.set_vexpand(True)
        self.grid.attach(self.scorllable_treelist, 0, 0, 8, 10)
        self.grid.attach_next_to(self.buttons[0], self.scorllable_treelist, Gtk.PositionType.BOTTOM, 1, 1)

        for i, button in enumerate(self.buttons[1:]):
            self.grid.attach_next_to(button, self.buttons[i], Gtk.PositionType.RIGHT, 1, 1)

        self.scorllable_treelist.add(self.treeview)
        self.show_all()

    def language_filter_func(self, model , iter, data):
        if(self.current_filter_language is None or self.current_filter_language == "None"):
            return True
        else:
            return model[iter][2] == self.current_filter_language


    def on_selection_button_clicked(self, widget):
        self.current_filter_language = widget.get_label()
        print("%s language selected!" % self.current_filter_language)

        self.language_filter.refilter()

if __name__ == '__main__':
    win = TreeViewFilterWindow()
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    Gtk.main()