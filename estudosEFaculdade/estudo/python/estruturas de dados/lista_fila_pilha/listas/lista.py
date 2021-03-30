#classe que cria  um nó lista
#nodelist
class nodeList:
    #classe que representa um nó de uma lista encadeada
    def __init__(self, value=0, next_node=None):
        self.value = value
        self.next_node = next_node
    def __repr__(self):
        return '%s ->   %s' % (self.value, self.next_node)
class nodeHead:
    def __init__(self):
        self.head = None
    def __repr__(self):
        return "[" + str(self.head) + "]"
def insertt(lista, data):
    data = nodeList(data)
    data.next_node = lista.head
    lista.head = data
def insert(lista, novo_dado, prev_data):
    #dado deve exister
    assert prev_data, "Nodo anterior precisa existir na lista."
    novo_dado = nodeList(novo_dado) #cria o nó
    novo_dado.next_node = prev_data.next_node
    prev_data.next_node = novo_dado
def search(lista, valor):
    corrent = lista.head
    aux = 0
    while corrent != None:
        if(corrent.value == valor):
            aux += 1
        corrent = corrent.next_node
    return aux
#remove elemento da lista
def remove(self, value):
    assert self.head   , "Impossivel remover da lista vazia"
    #nó a ser removido é a cabeça
    if(self.head.value == value):
        self.head = self.head.next_node
    else:
        prev = None #anterior
        corrente = self.head
        while corrente and corrente.value != value:
            prev = corrente
            corrente = corrente.next_node
        if corrente:
            prev.next_node = corrente.next_node
        else:
            prev.next_node = None
#limpa a lista
def cleanList(self):
    assert self.head, "Não há mais lista"
    while self.head:
        #remove a cabeça e a cabeça passa a ser o proximo nó
        self.head = self.head.next_node
    
    if(self.head == None):
        print("Lista Limpa com sucesso!")

#main
lista = nodeHead()
print("lista vazia:", lista )
insertt(lista, 0)
print("Lista contém um único elemento:", lista)
prev_node = lista.head
insert(lista, 1, prev_node)
insert(lista, 1, prev_node)
insert(lista, 5, prev_node)
insert(lista, 7, prev_node)
insert(lista, 10, prev_node)
insert(lista, 10, prev_node)
print("Inserindo um novo elemento:", lista)
ptList = lista.head
elem = 0
while ptList != None:
    elem = search(lista,ptList.value)
    if(elem >= 2):
        #remove o elemento
        remove(lista, ptList.value)
    else:
        elem = 0
    ptList = ptList.next_node
print("nova lista: ", lista)
cleanList(lista)

