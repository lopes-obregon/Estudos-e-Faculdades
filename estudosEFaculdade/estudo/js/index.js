class NodeList {
    constructor(value= undefined, next_node =null){
        this.value = value;
        this.next_node = next_node

    }
    get resultNode(){
        return `${this.value} -> `;
    }
}
class NodeHead{
    constructor(head= null){
        this.head = head
    }
    get result(){
        return "[" + String(this.head) + "]";
    }
}
class NodeFila{
    constructor(value= undefined, next_node = null){
        this.value = value;
        this.next_node = next_node;
    }
    get resultNode(){
        return `${this.value} -> `;
    }
}
class NodeHeadFila{
    constructor(ini = null, fin = null){
        this.ini = ini;
        this.fin = fin;
    }
}
function insert(list, new_data){
    let no = new NodeList(new_data); /**
     * criou o nó
     */
    no.next_node = list.head
    list.head = no

}
function print(list) {
    if(list === null){
        console.log(list);
        return null;
    }else{
        //console.log(list.resultNode);
        process.stdout.write(list.resultNode);
        list = list.next_node
        print(list);
    }
}
function clearList(list) {
    let aux = list.head;
    if(aux === null){
        return null;
    }else{
        list.head = aux.next_node;
        clearList(list);
    }
    
}
function remove(list, value) {
    let aux = list;
    while(list !== null){
        if(value == list.value){
            //remove
            aux.next_node = list.next_node;
        }
        aux = list;
        list = list.next_node;
    }
}
//função que faz a busca da lista
function search(list, value) {
    if( list === null){
        console.log("Elemento não encontrado!");
    }else{
        if(list.value == value){
            console.log("Elemento encontrado!");
        }else{
            if(list.value != value){
                list = list.next_node;
                search(list, value);
            }
        }
    }
    
}
//insere na fila
function insertQueue(queue, value) {
    //não tem ninguem na fila
    let no = new NodeFila(value);//cria o no
    if(queue.ini === null){
        queue.ini = no;
        queue.fin = no;
    }else{
        // já existe elemento na fila
        if(queue.ini === queue.fin){
            queue.ini.next_node = no;
            queue.fin = no;
        }else{
            queue.fin.next_node = no;
            queue.fin = no;
        }
    }
}
//função que imprime a fila
function printQueue(queue) {
    let aux = queue.ini;
    while(queue.ini !== null){
        process.stdout.write(queue.ini.resultNode);
        queue.ini = queue.ini.next_node;
    }
    if(queue.ini === null){
        console.log(queue.ini);
    }else{
        process.stdout.write(queue.ini.resultNode);
        queue.ini = queue.ini.next_node;
        printQueue(queue.ini);
    }
    queue.ini = aux;
}
//remove na fila
function removeQueue(queue) {
    let aux = queue.ini;
    //remove o elemento
    if(queue.ini === queue.fin){
        queue.ini = aux.next_node;
        queue.fin = aux.next_node;
    }else{
        queue.ini = aux.next_node;

    }
}
//limpa Fila 
function clearQueue(queue) {
    let aux = queue.ini;
    while(queue.ini !== null){
        if(queue.ini === queue.fin){
            queue.ini = null;
            queue.fin = null;
        }else{
            queue.ini = aux.next_node;
        }
    }
    if(queue.ini === null && queue.fin === null ){
        console.log("fila vazia");
    }
}
/**main */
/*let lista = new NodeHead();
console.log("LISTA VAZIA: ",lista.result);
insert(lista, 0);
insert(lista, 1);
insert(lista, 4);
console.log("Lista com Dados: ", lista.result);
console.log("imprimindo lista")
print(lista.head);
console.log("lista depois da remoção!");
print(lista.head);
console.log("REMOÇÃo");
remove(lista.head, 0);
print(lista.head);
search(lista.head, 1);
//search(lista.head, 8);
clearList(lista);
if(clearList(lista) === null){
    console.log("Lista limpa com sucesso!");
}*/
const fila = new NodeHeadFila();
console.log("Fila vazia: ", fila);
insertQueue(fila, 0);
insertQueue(fila, 40);
insertQueue(fila, 50);
insertQueue(fila, -10);
console.log("-----------------------------------------------");
printQueue(fila);
removeQueue(fila);
removeQueue(fila);
console.log("-----------------------------------------------");
printQueue(fila);
clearQueue(fila);
