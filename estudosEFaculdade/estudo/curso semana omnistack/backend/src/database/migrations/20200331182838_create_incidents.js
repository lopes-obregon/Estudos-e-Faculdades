
exports.up = function(knex) {
  	//cria a tabela
  return knex.schema.createTable('incidents', function(table){
  	table.increments();

  	table.string('title').notNullable();
  	table.string('descrption').notNullable();
  	table.decimal('value').notNullable();
  	//coluna para armazenar qual ong criou o incidente
  	table.string('ong_id').notNullable();

  	//chave estrangeira
  	table.foreign('ong_id').references('id').inTable('ongs');
  })
};

exports.down = function(knex) {
  return knex.schema.dropTable('incidents');
};
