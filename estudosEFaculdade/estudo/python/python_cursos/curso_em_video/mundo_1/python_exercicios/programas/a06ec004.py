var = input('Digite algo: ')


print('o tipo primitivo é {}\nsó tem espaço? {}\né um alfabeto? {}\né um número?  {}\né um alfanumérico?  {}\nestá em maiúscolo ?  {}\nestá em minuscolo ?  {}\nestá capitalizado?  {}\n '.format(type(var), var.isspace(), var.isalpha(), var.isnumeric(),var.isalnum(), var.isupper(), var.islower(), var.istitle()))
