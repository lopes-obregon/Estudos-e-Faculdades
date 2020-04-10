#calcular a quantidade de strings com letras maiuscolas e minuscolas
def func(string = ""):
    contador_maiuscolo = 0
    contador_minuscolo = 0

    tamanho_string = len(string)
    for i in range(tamanho_string):
        if(string[i].isupper()):# maiuscolas
            contador_maiuscolo += 1
        if(string[i].islower()):# minuscolas
            contador_minuscolo += 1
    print("Maiuscolas: ", contador_maiuscolo)
    print("Minuscolas: ", contador_minuscolo)


func("AbCD")