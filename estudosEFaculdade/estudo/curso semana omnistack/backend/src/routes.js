const express = require('express');
const OngController = require('./controllers/OngsController');
const routes = express.Router();
const IncidentController = require('./controllers/incedentController');
const ProfileController = require('./controllers/ProfileController');
const SessionController = require('./controllers/SessionController');
//async
//await
routes.post('/sessions', SessionController.create);
//lista de ongs
routes.get('/ongs', OngController.index);
//cadastro de ongs
//cria a primeira rota
routes.post('/ongs', OngController.create);
routes.get('/profile', ProfileController.index);

routes.get('/incidents', IncidentController.index);
routes.post('/incidents', IncidentController.create);
routes.delete('/incidents/:id', IncidentController.delete);

module.exports = routes;
