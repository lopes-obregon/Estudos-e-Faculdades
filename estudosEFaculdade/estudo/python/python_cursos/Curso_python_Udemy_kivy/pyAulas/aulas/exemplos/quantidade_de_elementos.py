Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> l = [1, 2, 3, 'arroz', 'batata', 19 , 78,]
>>> l
[1, 2, 3, 'arroz', 'batata', 19, 78]
>>> len(l)
7
>>> l[len(l)]
Traceback (most recent call last):
  File "<pyshell#3>", line 1, in <module>
    l[len(l)]
IndexError: list index out of range
>>> l[len(l) - 1]
78
>>> 

>>> l
[1, 2, 3, 'arroz', 'batata', 19, 78]
>>> l.insert(5, 'josé')
>>> l
[1, 2, 3, 'arroz', 'batata', 'josé', 19, 78]
>>> len(l)
8
>>> l.append('josess')
>>> l
[1, 2, 3, 'arroz', 'batata', 'josé', 19, 78, 'josess']
>>> l.count('josé')
1
>>> l.index('batata')
4
>>> l.index('1')
Traceback (most recent call last):
  File "<pyshell#14>", line 1, in <module>
    l.index('1')
ValueError: '1' is not in list
>>> l.index(1)
0
>>> 
