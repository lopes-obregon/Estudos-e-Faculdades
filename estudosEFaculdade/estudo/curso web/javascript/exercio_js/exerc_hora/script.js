var agora = new  Date()
var hora = agora.getHours()
$(function(){
	carrega_imagem()
})
//função que carrega a imagem
function carrega_imagem() {
	var img = document.getElementById('imagem')
	if(hora >= 18){
		//boa noite
		img.src = 'noite.jpg'
		$('#texto').text(`Agora são ${hora} Horas`)
		$('body').css('background-color', '#363636')
		$('h1').css('color', 'white')
	}
	else if (hora >= 13 && hora < 18) {
		//boa tarde
		img.src = 'campoTarde.jpg'
		$('#texto').text(`Agora são ${hora} Horas`)
		$('body').css('background-color', '#D2691E')
	}
	else if(hora < 13){
		img.src = 'bomDia.jpg'
		$('#texto').text(`Agora são ${hora} Horas`)
	}
}