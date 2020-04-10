Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> {}
{}
>>> type({})
<class 'dict'>
>>> d1 = {}
>>> type(d1)
<class 'dict'>
>>> d2 = dict()
>>> type(d2)
<class 'dict'>
>>> d1['aaa'] = 1000
>>> d1
{'aaa': 1000}
>>> d2 ['bbb'] = 2000
>>> d1['bbb'] = 2000
>>> d1['ccc'] = 3000
>>> d1
{'aaa': 1000, 'bbb': 2000, 'ccc': 3000}
>>> len(d1)
3
>>> {'aaa': 1000, 'bbb': 2000, 'ccc': 3000}
{'aaa': 1000, 'bbb': 2000, 'ccc': 3000}
>>> d1['bbb']
2000
>>> 29 - 14
15
>>> d2 = {1.1: "teste1", 2.2: "teste2", 3: "teste3"}
>>> d2
{1.1: 'teste1', 2.2: 'teste2', 3: 'teste3'}
>>> d2[1.1]
'teste1'
>>> d2[2.2]
'teste2'
>>> d2[3]
'teste3'
>>> d2[1.2]
Traceback (most recent call last):
  File "<pyshell#21>", line 1, in <module>
    d2[1.2]
KeyError: 1.2
>>> d2.keys(4)
Traceback (most recent call last):
  File "<pyshell#22>", line 1, in <module>
    d2.keys(4)
TypeError: keys() takes no arguments (1 given)
>>> #--------------- funcções dos dicionários --------------#
>>> tel = {}
>>> tel = {}
>>> tel = {}
>>> tel = {}
>>> tel
{}
>>> tel = {30301122: "Pericles", 33547877: "Menelau", 33381245: "Atreu", 36458899: "Tiestes"}
>>> print(tel)
{30301122: 'Pericles', 33547877: 'Menelau', 33381245: 'Atreu', 36458899: 'Tiestes'}
>>> len(4)
Traceback (most recent call last):
  File "<pyshell#31>", line 1, in <module>
    len(4)
TypeError: object of type 'int' has no len()
>>> len(tel)
4
>>> del(tel[36458899])#remove um elemento do dic
>>> print(tel)
{30301122: 'Pericles', 33547877: 'Menelau', 33381245: 'Atreu'}
>>> len(tel)
3
>>> tel.keys()#retorna a lista de chaves
dict_keys([30301122, 33547877, 33381245])
>>> tel.values() #retorna a lista dos valores
dict_values(['Pericles', 'Menelau', 'Atreu'])
>>> tel[30301122]
'Pericles'
>>> tel.get(30301122)
'Pericles'
>>> # retorna o valor ^
>>> tel = {30301122: "Pericles", 33547877: "Menelau", 33381245: "Atreu", 36458899: "Tiestes"}
>>> tel.popitem()
(36458899, 'Tiestes')
>>> tel
{30301122: 'Pericles', 33547877: 'Menelau', 33381245: 'Atreu'}
>>> tel.popitem()
(33381245, 'Atreu')
>>> tel
{30301122: 'Pericles', 33547877: 'Menelau'}
>>> tel.popitem()
(33547877, 'Menelau')
>>> tel
{30301122: 'Pericles'}
>>> tel.popitem()
(30301122, 'Pericles')
>>> tel
{}
>>> #retorna o ultimo elemento e depois remove o elemento ^
>>> tel = {30301122: "Pericles", 33547877: "Menelau", 33381245: "Atreu", 36458899: "Tiestes"}
>>> 36458899 in tel
True
>>> 366458899 in tel
False
>>> tel2 = {999999999: "teste1", 55551111: "teste2"}
>>> tel2
{999999999: 'teste1', 55551111: 'teste2'}
>>> tel.update(tel2) #une as duas lista em uma unica lista
>>> tel
{30301122: 'Pericles', 33547877: 'Menelau', 33381245: 'Atreu', 36458899: 'Tiestes', 999999999: 'teste1', 55551111: 'teste2'}
>>> t = (10,10,10)
>>> tel[t] = "eXcript"
>>> tel
{30301122: 'Pericles', 33547877: 'Menelau', 33381245: 'Atreu', 36458899: 'Tiestes', 999999999: 'teste1', 55551111: 'teste2', (10, 10, 10): 'eXcript'}
>>> #testando o dic
>>> dic = dict()
>>> dic
{}
>>> 123 - 96
27
>>> 122 -97
25
>>> text = 97
>>> for i in range(25):
	dic[i] = chr(text)
	text += 1

	
>>> dic
{0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h', 8: 'i', 9: 'j', 10: 'k', 11: 'l', 12: 'm', 13: 'n', 14: 'o', 15: 'p', 16: 'q', 17: 'r', 18: 's', 19: 't', 20: 'u', 21: 'v', 22: 'w', 23: 'x', 24: 'y'}
>>> 
