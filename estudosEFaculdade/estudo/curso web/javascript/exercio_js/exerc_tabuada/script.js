var pai = document.getElementById('resultado')
$(function(){
	
	//main
	$('#button').click(function(){
		//variaveis
		$('option').remove()
		var valor = $('input[type=number][name=numero]').val()
		valor = Number(valor)
		gera_tabuada(valor)
	})
})

function gera_tabuada(num) {
	for(var i = 0; i <= 10; i++){
		$('#resultado').append(`<option>${num} * ${i} = ${i*num}</option>`)
	}
}