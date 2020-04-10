//api do node
// importar
//const cors = require('cors') instalar quando tiver internet
const express = require('express');
const routes = require('./routes');
//cria a aplicação ou instancia
const app = express();
//app.use(cors()); 
app.use(express.json());
app.use(routes)
/**
*	Metodos http:
*get: buscar/listar uma informação do back-end
*post: Criar uma infromação no back-end
*put: alterar uma informção no back-end
*delete: deletar uma infromação no back-end
*/
/**
*tipos de parâmetros:
*query: parâmetros  nomeados enviados na rota após '?', (filtros, paginação)
* route params: parâmetros para identificar 
*request body: Corpo da reqiosição, utilizado para criar ou alterar recursos
*/

//acessa a porta 3333 do local host
app.listen(3333);
