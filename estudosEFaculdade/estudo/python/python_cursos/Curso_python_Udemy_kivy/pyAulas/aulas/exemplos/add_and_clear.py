Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> l = ['bbb', 'ccc', 'ddd',]
>>> l
['bbb', 'ccc', 'ddd']
>>> l[0]
'bbb'
>>> l.append('eee')
>>> l
['bbb', 'ccc', 'ddd', 'eee']
>>> l.insert(0, 'aaa')
>>> l
['aaa', 'bbb', 'ccc', 'ddd', 'eee']
>>> l[1]
'bbb'
>>> l[1] = 'bbbb'
>>> l[1]
'bbbb'
>>> l
['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
[
>>> l.clear()
>>> l
[]
>>> l = ['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> l
['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> l
['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> l.pop()
'eee'
>>> l
['aaa', 'bbbb', 'ccc', 'ddd']
>>> l.pop(0)
'aaa'
>>> l.pop(-1)
'ddd'
>>> l = ['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> l
['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> del (l[2:4])
>>> l
['aaa', 'bbbb', 'eee']
>>> l = ['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> l
['aaa', 'bbbb', 'ccc', 'ddd', 'eee']
>>> del(l[::2])
>>> l
['bbbb', 'ddd']
>>> 
