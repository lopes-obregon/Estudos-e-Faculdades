#script que gerencia uma fila
#classe que cria o nó
class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next_node = next_node
    def __repr__(self):
        return '%s -> %s' %(self.data, self.next_node)
#nó com os ponteiros da fila
class Fila:
    def __init__(self):
        self.frist = None
        self.last = None

    def __repr__(self):
        return "[" + str(self.frist) + "]"
    #insere elemento no final da fila
    def insert(self, newData):
        newData = Node(newData)
        #insere em uma fila vazia
        if(self.frist == None):
            self.frist = newData
            self.last = newData
        else:
            #faz o Nó ser o ultimo
            self.last.next_node = newData
            #faz o ponteiro apontar para esse novo elemento
            self.last = newData
    #remove elemento da fila
    def remove(self):
        if(self.frist == None):
            print("Impossivel remover da fila vazia")
        #o ponteiro do primeiro aponta para o proximo da fila
        self.frist = self.frist.next_node
        #caso o primeiro chegou no final da fila ou seja em lambda
        if(self.frist == None):
            self.last = None
    def clean(self):
        assert self.frist == None, "Não tem mais fila"
        #
        while self.frist:
            self.frist = self.frist.next_node
            if(self.frist == None):
                self.last = None
        if(self.frist == None):
            print("Fila vazia")

#main
fila = Fila()
print("FIla fazia", fila)
for i in range(0, 10):
    fila.insert(i)

print("Fila com elementos: ", fila)
for i in range(0 ,10):
    fila.remove()
    print("Removendo o elemento de começo da fila", fila)
fila.clean()

