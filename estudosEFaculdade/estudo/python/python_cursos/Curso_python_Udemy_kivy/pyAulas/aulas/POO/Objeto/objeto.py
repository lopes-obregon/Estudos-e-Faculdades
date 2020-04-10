Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> class MinhaClasse:
	pass

>>> obj = MinhaClasse()
>>> #gerou uma instancia
>>> type(obj)
<class '__main__.MinhaClasse'>
>>> type(MinhaClasse)
<class 'type'>
>>> obj.__
Traceback (most recent call last):
  File "<pyshell#7>", line 1, in <module>
    obj.__
AttributeError: 'MinhaClasse' object has no attribute '__'
>>> obj.__class__
<class '__main__.MinhaClasse'>
>>> MinhaClasse.__class__
<class 'type'>
>>> obj.__name__
Traceback (most recent call last):
  File "<pyshell#10>", line 1, in <module>
    obj.__name__
AttributeError: 'MinhaClasse' object has no attribute '__name__'
>>> MinhaClasse.__name__
'MinhaClasse'
>>> obj.__class__.__name__
'MinhaClasse'
>>> 
>>> 
>>> 
>>> 
>>> MinhaClasse.var_cls = 0
>>> MinhaClasse
<class '__main__.MinhaClasse'>
>>> print(MinhaClasse)
<class '__main__.MinhaClasse'>
>>> MinhaClasse.__dict__
mappingproxy({'__module__': '__main__', '__dict__': <attribute '__dict__' of 'MinhaClasse' objects>, '__weakref__': <attribute '__weakref__' of 'MinhaClasse' objects>, '__doc__': None, 'var_cls': 0})
>>> from pprint import pprint
>>> pprint(MinhaClasse.__dict__)
mappingproxy({'__dict__': <attribute '__dict__' of 'MinhaClasse' objects>,
              '__doc__': None,
              '__module__': '__main__',
              '__weakref__': <attribute '__weakref__' of 'MinhaClasse' objects>,
              'var_cls': 0})
>>> pprint(obj.var_cls)
0
>>> MinhaClasse.var_cls = 10
>>> obj.var_cls
10
>>> 
