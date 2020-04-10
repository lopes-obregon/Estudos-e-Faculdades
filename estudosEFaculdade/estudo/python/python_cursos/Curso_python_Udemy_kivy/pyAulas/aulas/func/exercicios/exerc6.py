def func(a, b):
    def func1():
        print("func invocou func1")
        def func2():
            x = a
            y = b
            print("valores calculados de x e y: ", x, y)
            print("func1 invocou func 2")
            resultado = x + y
            return resultado
        return  func2()
    print(func1())


func(10,142)