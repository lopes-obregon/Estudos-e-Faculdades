import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk
import math
class Handler(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Calculadora")
        self.num1 = builder.get_object("entry1")
        self.num2 = builder.get_object("entry2")
        self.labelResposta = builder.get_object("resposta")

    def onDestroy(self, *args):
        Gtk.main_quit()

    def onButtonPressedSoma(self, button):
        self.labelResposta.set_text(str(float(self.num1.get_text()) + float(self.num2.get_text())))

    def onButtonPressedSub(self, button):
        self.labelResposta.set_text(str(float(self.num1.get_text()) - float(self.num2.get_text())))

    def onButtonPressedMult(self, button):
        self.labelResposta.set_text(str(float(self.num1.get_text()) * float(self.num2.get_text())))

    def onButtonPressedDiv(self, button):
        self.labelResposta.set_text(str(float(self.num1.get_text()) / float(self.num2.get_text())))

    def onButtonPressedDobro(self, button):
        if(self.num2.get_text() == ""):
            self.labelResposta.set_text("O dobro do numéro é:" + str(float(self.num1.get_text()) * 2))
        elif(self.num1.get_text() == ""):
            self.labelResposta.set_text("O dobro do numéro é:" + str(float(self.num2.get_text())*2))

        elif(self.num1.get_text() != "" and self.num2.get_text() != ""):
            self.labelResposta.set_text("O dobro do seus dois numéros é:" + str(float(self.num1.get_text())*2) + ", " + str(float(self.num2.get_text())*2))
        elif(self.num1.get_text() == "" and self.num2.get_text() == ""):
            self.labelResposta.set_text("Por favor insira um numéro para calcular")

    def onButtonPressedTriplo(self, button):
        if(self.num1.get_text() == ""):
            self.labelResposta.set_text("O triplo do numéro é: " + str(float(self.num2.get_text())*3))
        elif(self.num2.get_text() == ""):
            self.labelResposta.set_text("O triplo do numéro é: " + str(float(self.num1.get_text())*3))
        elif(self.num1.get_text() != "" and  self.num2.get_text() != ""):
            self.labelResposta.set_text("O triplo do seu dois numéros é: " + str(float(self.num1.get_text())*3) + ", " + str
            (float(self.num2.get_text())*3))

    def onButtonPressedRaiz(self, button):
        if(self.num1.get_text() == ""):
            self.labelResposta.set_text("A raiz do numéro é: " + str(math.sqrt(float(self.num2.get_text()))))
        elif(self.num2.get_text() == ""):
            self.labelResposta.set_text("A raiz do numéro é: " + str(math.sqrt(float(self.num1.get_text()))))

        elif(self.num1.get_text() != "" and self.num2.get_text() != ""):
            self.labelResposta.set_text("A raiz dos dois  numéro é: " + str(math.sqrt(float(self.num1.get_text()))) + ", " + str(math.sqrt(float(self.num2.get_text()))))

if __name__ == '__main__':
    builder = Gtk.Builder()
    builder.add_from_file("calc.glade")
    builder.connect_signals(Handler())
    window = builder.get_object("window1")
    window.show_all()

    Gtk.main()