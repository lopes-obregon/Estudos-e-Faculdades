Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> x = 4
>>> x in [1,3,5,]
False
>>> x in [1, 2, 3, 4,]
True
>>> x in (1, 2, 3)
False
>>> x in (1, 4, 5)
True
>>> type(x)
<class 'int'>
>>> type(z)
Traceback (most recent call last):
  File "<pyshell#6>", line 1, in <module>
    type(z)
NameError: name 'z' is not defined
>>> 6 in range(1, 6)
False
>>> x = range(1, 6)
>>> if 3 in x:
	print("contido")
	else:
		
SyntaxError: invalid syntax
>>> if 3 in x:
	print("contido")
else:
	print("não esta contido")

	
contido
>>> 
