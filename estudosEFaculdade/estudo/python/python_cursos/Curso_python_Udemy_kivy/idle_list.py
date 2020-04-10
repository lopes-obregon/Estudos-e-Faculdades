Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> lista = [1, 2, 8, 5, 15, 3, 6, 8]
>>> lista
[1, 2, 8, 5, 15, 3, 6, 8]
>>> ['ffa', 3, "desf"]
['ffa', 3, 'desf']
>>> type({})
<class 'dict'>
>>> lista[0]
1
>>> lista[1]
2
>>> lista[5]
3
>>> lista[1] + lista[2]
10
>>> l = ['a', 'b', 'c', 'd', 'e']
>>> l
['a', 'b', 'c', 'd', 'e']
>>> l[0]
'a'
>>> l[3]
'd'
>>> 
=============================== RESTART: Shell ===============================
>>> lista = list ("eXcript")
>>> lista
['e', 'X', 'c', 'r', 'i', 'p', 't']
>>> lista = list(("renan",))
>>> lista
['renan']
>>> len(lista)
1
>>> len("renan lopes obregon")
19
>>> lista = list(('a', 32, 49, 50, 39))
>>> lista[-1]
39
>>> lista[0][-1]
'a'
>>> #mais ou menos uma linha
>>> lista = [1, 2, 3, 4, 5]
>>> lista
[1, 2, 3, 4, 5]
>>> lista = lista + [6]
>>> lista
[1, 2, 3, 4, 5, 6]
>>> lista = [0] + lista
>>> lista
[0, 1, 2, 3, 4, 5, 6]
>>> lista = lista + [7, 8, 9, 10]
>>> list
<class 'list'>
>>> lista
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
>>> lista.append(11)
>>> lista
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
>>>  lista.append([11])
SyntaxError: unexpected indent
>>> lista.append([1])
>>> lista
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, [1]]
>>> del(lista[-1])
>>> lista
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
>>> 10+[0]
Traceback (most recent call last):
  File "<pyshell#38>", line 1, in <module>
    10+[0]
TypeError: unsupported operand type(s) for +: 'int' and 'list'
>>> 10*[0]
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
>>> lista += 10 * [0]
>>> lista
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
>>> 50 *"-"
'--------------------------------------------------'
>>> 
