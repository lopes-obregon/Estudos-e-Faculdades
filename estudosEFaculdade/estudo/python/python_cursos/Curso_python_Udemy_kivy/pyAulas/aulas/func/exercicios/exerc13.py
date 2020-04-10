#inverta a lista atravez de funções
def func(*args):
    string = ""
    for i in range(7, -1, -1):
      string = string +  str(args[i])
    print(string)


func(*"1234abcd")# desta forma separa as tuplas