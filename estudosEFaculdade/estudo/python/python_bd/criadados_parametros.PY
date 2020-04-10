#coding: utf-8
__author__ = 'Renan Lopes Obregon'
#programa que entra com os dados no banco de dados
import sqlite3
conn = sqlite3.connect('clientes.db')
cursor = conn.cursor()
#ssolicitando os dados do usuário
cursor.execute("""CREATE TABLE clientes (
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        nome TEXT NOT NULL,
        idade INTEGER,
        cpf     VARCHAR(11) NOT NULL,
        email TEXT NOT NULL,
        fone TEXT,
        cidade TEXT,
        uf VARCHAR(2) NOT NULL,
        criado_em DATE NOT NULL
);""")

nome = input("Nome: ")
idade = input('Idade: ')
cpf = input('CPF: ')
email = input('Email: ')
fone = input('Fone: ')
cidade = input('Cidade: ')
uf = input('UF: ')
criado_em = input('Cirado em (yyyy-mm-dd): ')

#inserindo dados na tabela
cursor.execute(""" INSERT INTO clientes (nome, idade, cpf, email, fone, cidade, uf, criado_em) VALUES (?,?,?,?,?,?,?,?)""",(nome, idade, cpf, email, fone, cidade, uf, criado_em))
conn.commit()
print("dados gravados")
conn.close()
