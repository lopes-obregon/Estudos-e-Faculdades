var data = new Date()
var ano = data.getFullYear()
var radios = document.getElementsByName("gener")
var radioEscolido = 'a'
$(function(){
	var idade = $('input[type=text][name=idade]').val()
	$('#verifica').click(function(){
		if (idade == 'Valor') {
			alert('Por favor verifica a idade')
		}else{
			idade = Number(idade)
		}
		var idadePessoa = ano - idade
		for(var i = 0; i < radios.length; i++){
			if (radios[i].checked) {
				radioEscolido = radios[i].value
			}
		}
				
		carrega_imagem(idadePessoa, radioEscolido)	
			
		
	})
	
})
function carrega_imagem(idade, escolido){
	var img = document.getElementById('imagem')
	if (idade <= 50 && escolido == 'F') {
		//mulher
		img.src = 'fotos/jovem_feminina.jpg'
		$('#msg').text(`Detectamos Uma Mulher com ${idade} anos`)

	}
	else if (idade > 50 && escolido == 'F') {
		//mulher com idade avançada
		img.src = 'fotos/senhora.jpg'
		$('#msg').text(`Detectamos Uma Mulher com ${idade} anos`)
	}
	else if (idade <= 50 && escolido == 'M') {
		//homem 
		img.src = 'fotos/jovem_adulto.jpg'
		$('#msg').text(`Detectamos Um Homem com ${idade} anos`)
	}
	else if (idade > 50 && escolido == 'M'){
		//homem com idade avançada
		img.src = 'fotos/senhor_idoso.jpg'
		$('#msg').text(`Detectamos Um Homem com ${idade} anos`)
	}
}