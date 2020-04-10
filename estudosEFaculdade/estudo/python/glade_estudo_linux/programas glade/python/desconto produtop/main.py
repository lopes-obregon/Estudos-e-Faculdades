import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class Handler:
    def __init__(self):
        self.preco = builder.get_object("preco")
        self.resultado = builder.get_object("label")
        self.por = builder.get_object("porcento")
    def onDestroy(self, *args):
        Gtk.main_quit()

    def onButtonPressed(self, button):
        #if(self.por.get_text() == ""):
         #   self.resultado.set_text("Por favor informe o valor de desconto!")
        #else:
            porcento = float(self.por.get_text())/100
            desconto = float(self.preco.get_text())*porcento
            print(desconto)
            self.resultado.set_text("O valor do produto com 5% de desconto é: "  + str(desconto))

if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("desconto_produto.glade")
    builder.connect_signals(Handler())

    window = builder.get_object("window1")
    window.show_all()

    Gtk.main()