//var idade = $('input[type=text][name=idade]').val()
$(function(){
	//main
	//variaveis
	
	//codigo
	
	/*devemos contar de inicio até o fim, o passo serve para saber de quantos em quantos a distancia dos números*/
	$('input[type=submit][name=submit]').click(function(){
		var inicio = $('input[type=number][name=inicio]').val()
		var fim = $('input[type=number][name=fim]').val()
		var passo = $('input[type=number][name=passo]').val()
		if (Number(passo) == 0) {
			alert("Por favor insira um passo valido impossivel pular de 0 em 0")
		}else{
				$('[class="print"').remove()
				let i = Number(inicio)
				while(i <= Number(fim)){
					$('#resultado').append(`<label class="print"> ${i}</label> `)
					i += Number(passo)
				}
					}
	})
	
})
