Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> l = ['ddd', 'ccc', 'a',]
>>> l.reverse()
>>> 
>>> l
['a', 'ccc', 'ddd']
>>> l.reverse()
>>> l
['ddd', 'ccc', 'a']
>>> l = ['ggg']
>>> l
['ggg']
>>> l = ['ddd', 'ccc', 'a',]
>>> l
['ddd', 'ccc', 'a']
>>> l.append('g')
>>> l
['ddd', 'ccc', 'a', 'g']
>>> l.sort()
>>> l
['a', 'ccc', 'ddd', 'g']
>>> l.sort(reverse = True)
>>> l
['g', 'ddd', 'ccc', 'a']
>>> 
