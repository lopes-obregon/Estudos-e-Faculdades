import gi

gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


class LabelWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Label Example")

        hbox = Gtk.Box(spacing=10)
        hbox.set_homogeneous(False)
        vbox_left = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        vbox_left.set_homogeneous(False)
        vbox_right = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        vbox_right.set_homogeneous(False)

        hbox.pack_start(vbox_left, True, True, 0)
        hbox.pack_start(vbox_right, True, True, 0)

        label = Gtk.Label("Este é uma label normal")
        #This is a normal label"
        vbox_left.pack_start(label, True, True, 0)

        label = Gtk.Label()
        label.set_text("Este é uma label justificado à esquerda.\n Com várias linhas")
        #This is a left-justified label.\nWith multiple lines."
        label.set_justify(Gtk.Justification.LEFT)
        vbox_left.pack_start(label, True, True, 0)

        label = Gtk.Label(
            "Este é uma label justificada à direita.\n Com várias linhas")
        #This is a right-justified label.\nWith multiple lines.
        label.set_justify(Gtk.Justification.RIGHT)
        vbox_left.pack_start(label, True, True, 0)

        label = Gtk.Label("Este é um exemplo de um rótulo enrolado em linha."
                           "não deveria estar tomando o todo"
                           "largura alocada a ele, mas automaticamente"
                           "encapsula as palavras para caber. \ n"
                           "Ele suporta vários parágrafos corretamente"
                           "e adiciona corretamente"
                           "muitos espaços extras.")
        label.set_line_wrap(True)
        vbox_right.pack_start(label, True, True, 0)

        label = Gtk.Label("Este é um exemplo de um rótulo preenchido com linha."
                           "Deveria estar tomando"
                           "a largura inteira alocada a ele."
                           "Aqui está uma frase para provar"
                           "meu ponto. Aqui está outra sentença."
                           "Aqui vem o sol, do fazer. \ N"
                           "Este é um novo parágrafo. \ N"
                           "Este é outro mais novo, mais longo, melhor"
                           "parágrafo. Está chegando ao fim"
                           "infelizmente.")
        label.set_line_wrap(True)
        label.set_justify(Gtk.Justification.FILL)
        vbox_right.pack_start(label, True, True, 0)

        label = Gtk.Label()
        label.set_markup("Text can be <small>small</small>, <big>big</big>, "
                         "<b>bold</b>, <i>italic</i> and even point to "
                         "somewhere in the <a href=\"http://www.gtk.org\" "
                         "title=\"Click to find out more\">internets</a>.")
        label.set_line_wrap(True)
        vbox_left.pack_start(label, True, True, 0)

        label = Gtk.Label.new_with_mnemonic(
            "_Press Alt + P to select button to the right")
        vbox_left.pack_start(label, True, True, 0)
        label.set_selectable(True)

        button = Gtk.Button(label="Click at your own risk")
        label.set_mnemonic_widget(button)
        vbox_right.pack_start(button, True, True, 0)

        self.add(hbox)

if __name__ == '__main__':

    window = LabelWindow()
    window.connect("destroy", Gtk.main_quit)
    window.show_all()
    Gtk.main