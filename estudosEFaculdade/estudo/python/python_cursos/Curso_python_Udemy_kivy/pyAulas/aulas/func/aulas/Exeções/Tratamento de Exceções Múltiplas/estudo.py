#coding: utf-8
#author: Renan Lopes Obregon

def erro(x):
    try:
        eval(x)
    except (TypeError, NameError) as e:
        print("TypeError ocorreu ou então, NameError")
    except ValueError as e:
        print("ValueError")
        print(type(e))#obtendo a instância da exceção
        print(e.args)#obtendo os argumentos as mensaguens
        print(e)#__str__ mensagem
    except ZeroDivisionError:
        print("ZeroDivisionError")

#main

# #TypeError
erro("int + int")
# #NameErro
erro("a")
#ValueError
erro("int('a')")

# erro("10/0")
# erro("10 + 10")
print("A aplicação foi finalizada")