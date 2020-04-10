#coding: utf-8
__author = 'Renan Lopes Obregon'
import sqlite3
if __name__ == '__main__':
    conn = sqlite3.connect( 'clientes.db')
    cursor = conn.cursor()
    #lendo os dados
    cursor.execute("""SELECT * FROM clientes;""")
    for linha in cursor.fetchall():
        print(linha)
    conn.close()