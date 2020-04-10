//primeiro pega o valor
//variavel global
var num = []
$(function(){

})

function adiciona(){
	//variavel local
	let valor_input = $('input[type=number][name=num]').val()
	//coding
	//limpa os filhos do pai no caso da tag selection
	$('option').remove()
	valor_input = Number(valor_input)
	//verifica o valor se pertence ao intervalo ou nao
	if(valor_input > 100){
		alert("Valor fora do intervalo por favor insira valores do intervalo de 1 a 100")
	}
	else if(valor_input < 1){
		alert('intervalo permetido de 1 a 100')
	}
	else if(valor_input >= 1 && valor_input <= 100){
		num.push(valor_input)
		for(let i in num){
			//primeiro verifica se ja foi imprimido
			$('#resultado').append(`<option> Valor ${num[i]} Adicionado.`)
				
		}
		
	}
}
//função que imprime os resultados
function resultados_array(){
	//$('#container').append('<p>testando os filhos</p>')
	$('[class="print"').remove()
	$('#container').append(`<p class="print">Ao todo, temos ${num.length} números cadastrados.</p>`)
	$('#container').append(`<p class="print"> O maior valor informado foi ${encontra_maior()}.`)
	$('#container').append(`<p class="print"> O menor valor informado foi ${encontra_menor()}.</p>`)
	$('#container').append(`<p class="print"> A somando todos os valores, temos ${soma_lista()}.</p>`)
	$('#container').append(`<p class="print"> A média dos valores digitados é ${calc_media()}.</p>`)
}
//função que encontra o maior número
function encontra_maior(){
	let maior = 0
	for(let i in num){
		if(num[i] > maior){
			maior = num[i]
		}
	}
	return maior
}
//função que encontra o menor número
function encontra_menor() {
	let menor = 99999
	for(let i in num){
		if (num[i] < menor) {
			menor = num[i]
		}
	}
	return menor
}
//função que soma todos os valores da lista
function soma_lista(){
	let soma = 0
	for(let i in num){
		soma += num[i]
	}
	return soma
}
//função que calcula a média dos numeros
function calc_media(){
	let soma = 0
	for(let i in num){
		soma += num[i]
	}
	return soma/num.length

}