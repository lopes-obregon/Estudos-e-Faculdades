const knex = require('knex');
const configurtion = require('../../knexfile');

const connection = knex(configurtion.development);

module.exports = connection;