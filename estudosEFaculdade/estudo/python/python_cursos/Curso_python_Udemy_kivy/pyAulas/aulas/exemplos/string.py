Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> Python 3.6.7 (default, Oct 22 2018, 11:32:17) 
[GCC 8.2.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> 'String com aspas simpes'
'String com aspas simpes'
>>> s1 = 'String com aspas simpes'
>>> print(s1)
String com aspas simpes
>>> s2 = "tring com aspas simpes"
>>> s1
'String com aspas simpes'
>>> s2
'tring com aspas simpes'
>>> s2 = "String com aspas dupla"
>>> 
>>> s2
'String com aspas dupla'
>>> s3 = '''aaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbb
ccccccccccccccccc
d
dddddddddddddddddddddd
eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
rrrrrrrrrrrrrrrrr'''
>>> s3
'aaaaaaaaaaaaaaa\nbbbbbbbbbbbbbbbbbbb\nccccccccccccccccc\nd\ndddddddddddddddddddddd\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\nrrrrrrrrrrrrrrrrr'
>>>  s4 = """aaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbb
ccccccccccccccccc
d
dddddddddddddddddddddd
eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
rrrrrrrrrrrrrrrrr"""
SyntaxError: unexpected indent
>>> s4 = """aaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbb
ccccccccccccccccc
d
dddddddddddddddddddddd
eeeeeeeeeeee
SyntaxError: unexpSyntaxError: unexpected indent"""
>>> s4
'aaaaaaaaaaaaaaa\nbbbbbbbbbbbbbbbbbbb\nccccccccccccccccc\nd\ndddddddddddddddddddddd\neeeeeeeeeeee\nSyntaxError: unexpSyntaxError: unexpected indent'
>>> print(s3)
aaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbb
ccccccccccccccccc
d
dddddddddddddddddddddd
eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
rrrrrrrrrrrrrrrrr
>>> s = "Para o python, toda String é uma lista imutável."
>>> print(s)
Para o python, toda String é uma lista imutável.
>>> s[0]
'P'
>>> type(s[0])
<class 'str'>
>>> s[-1]
'.'
>>> for i in range(97, 123):
	print(str(i))

	
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
>>> str(97)
'97'
>>> str(61)
'61'
>>> chr(97)
'a'
>>> for i in range(97, 123):
	print(chr(i))

	
a
b
c
d
e
f
g
h
i
j
k
l
m
n
o
p
q
r
s
t
u
v
w
x
y
z
>>> #----------------------------- voltando a aula
>>> s[5:10]
'o pyt'
>>> s[5:20]
'o python, toda '
>>> len(s)
48
>>> s[5:]
'o python, toda String é uma lista imutável.'
>>> s[::-1]
'.levátumi atsil amu é gnirtS adot ,nohtyp o araP'
>>> s[::2]
'Pr  yhn oaSrn  m it mtvl'
>>> s[::5]
'PohtSgmsme'
>>> #----------------- fatiando string
>>> #------------------comparando strings------------------#
>>> "a" > "X"
True
>>> "a" > "1"
True
>>> "a" > "9"
True
>>> chr(100)
'd'
>>> ord("d")
100
>>> for c in range(122):
	chr(c)

	
'\x00'
'\x01'
'\x02'
'\x03'
'\x04'
'\x05'
'\x06'
'\x07'
'\x08'
'\t'
'\n'
'\x0b'
'\x0c'
'\r'
'\x0e'
'\x0f'
'\x10'
'\x11'
'\x12'
'\x13'
'\x14'
'\x15'
'\x16'
'\x17'
'\x18'
'\x19'
'\x1a'
'\x1b'
'\x1c'
'\x1d'
'\x1e'
'\x1f'
' '
'!'
'"'
'#'
'$'
'%'
'&'
"'"
'('
')'
'*'
'+'
','
'-'
'.'
'/'
'0'
'1'
'2'
'3'
'4'
'5'
'6'
'7'
'8'
'9'
':'
';'
'<'
'='
'>'
'?'
'@'
'A'
'B'
'C'
'D'
'E'
'F'
'G'
'H'
'I'
'J'
'K'
'L'
'M'
'N'
'O'
'P'
'Q'
'R'
'S'
'T'
'U'
'V'
'W'
'X'
'Y'
'Z'
'['
'\\'
']'
'^'
'_'
'`'
'a'
'b'
'c'
'd'
'e'
'f'
'g'
'h'
'i'
'j'
'k'
'l'
'm'
'n'
'o'
'p'
'q'
'r'
's'
't'
'u'
'v'
'w'
'x'
'y'
>>> for  c in range(123):
	str(c + " - " + chr(c))

	
Traceback (most recent call last):
  File "<pyshell#56>", line 2, in <module>
    str(c + " - " + chr(c))
TypeError: unsupported operand type(s) for +: 'int' and 'str'
>>> for  c in range(123):
	str(c) + " - " + chr(c)

	
'0 - \x00'
'1 - \x01'
'2 - \x02'
'3 - \x03'
'4 - \x04'
'5 - \x05'
'6 - \x06'
'7 - \x07'
'8 - \x08'
'9 - \t'
'10 - \n'
'11 - \x0b'
'12 - \x0c'
'13 - \r'
'14 - \x0e'
'15 - \x0f'
'16 - \x10'
'17 - \x11'
'18 - \x12'
'19 - \x13'
'20 - \x14'
'21 - \x15'
'22 - \x16'
'23 - \x17'
'24 - \x18'
'25 - \x19'
'26 - \x1a'
'27 - \x1b'
'28 - \x1c'
'29 - \x1d'
'30 - \x1e'
'31 - \x1f'
'32 -  '
'33 - !'
'34 - "'
'35 - #'
'36 - $'
'37 - %'
'38 - &'
"39 - '"
'40 - ('
'41 - )'
'42 - *'
'43 - +'
'44 - ,'
'45 - -'
'46 - .'
'47 - /'
'48 - 0'
'49 - 1'
'50 - 2'
'51 - 3'
'52 - 4'
'53 - 5'
'54 - 6'
'55 - 7'
'56 - 8'
'57 - 9'
'58 - :'
'59 - ;'
'60 - <'
'61 - ='
'62 - >'
'63 - ?'
'64 - @'
'65 - A'
'66 - B'
'67 - C'
'68 - D'
'69 - E'
'70 - F'
'71 - G'
'72 - H'
'73 - I'
'74 - J'
'75 - K'
'76 - L'
'77 - M'
'78 - N'
'79 - O'
'80 - P'
'81 - Q'
'82 - R'
'83 - S'
'84 - T'
'85 - U'
'86 - V'
'87 - W'
'88 - X'
'89 - Y'
'90 - Z'
'91 - ['
'92 - \\'
'93 - ]'
'94 - ^'
'95 - _'
'96 - `'
'97 - a'
'98 - b'
'99 - c'
'100 - d'
'101 - e'
'102 - f'
'103 - g'
'104 - h'
'105 - i'
'106 - j'
'107 - k'
'108 - l'
'109 - m'
'110 - n'
'111 - o'
'112 - p'
'113 - q'
'114 - r'
'115 - s'
'116 - t'
'117 - u'
'118 - v'
'119 - w'
'120 - x'
'121 - y'
'122 - z'
>>> #-------------------propriedades das strings------------------------
>>> s = "Lista de Caracteres"
>>> len(s)
19
>>> len("")
>>>print(s)

SyntaxError: invalid syntax
>>> s
Traceback (most recent call last):
  File "<pyshell#1>", line 1, in <module>
    s
NameError: name 's' is not defined
>>> s = "Lista de Caracteres"
>>> len("")
0
>>> len("0")
1
>>> print(s)
Lista de Caracteres
>>> s[5]
' '
>>> s[6]
'd'
>>> s[6] = "x"
Traceback (most recent call last):
  File "<pyshell#8>", line 1, in <module>
    s[6] = "x"
TypeError: 'str' object does not support item assignment
>>> s.split(" ")
['Lista', 'de', 'Caracteres']
>>> lista = s.split(" ")
>>> lista
['Lista', 'de', 'Caracteres']
>>> lista[0] + " " + lista[2]
'Lista Caracteres'
>>> s.replace("de", "")
'Lista  Caracteres'
>>> id(s)
140231863415120
>>> id(s.replace("de", ""))
140231863415048
>>> s.replace("de", "")
'Lista  Caracteres'
>>> id(s.replace("de", ""))
140231749691768
>>> id(s.replace("de", ""))
140231863415048
>>> id(s.replace("de", ""))
140231863415048
>>> id(s.replace("de", ""))
140231863415048
>>> 
