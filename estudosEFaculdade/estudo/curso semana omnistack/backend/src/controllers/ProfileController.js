const connection = require('../database/connect');

module.exports = {
	async index(request, response){
		const ong_id = request.headrs.authorization;
		const incidents = await connection('incidents')
			.where('ong_id', ong_id)
			.select('*')

		return response.json(incidents);
	}
}