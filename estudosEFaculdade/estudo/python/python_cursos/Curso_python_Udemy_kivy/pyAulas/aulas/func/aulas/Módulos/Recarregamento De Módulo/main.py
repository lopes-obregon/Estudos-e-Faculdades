#coding: utf-8

import importlib
import mod_a
del (mod_a.b) #remove o valor b
importlib.reload(mod_a)#reimporta o módulo
mod_a.a = 0

from pprint import pprint

pprint(mod_a.__dict__)