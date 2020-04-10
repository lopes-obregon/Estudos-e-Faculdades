var radios = document.getElementsByName('gener')

//verifica a escolha
for (var i = 0; i < radios.length; i++) {
	if(radios[i].checked){
		console.log(radios[i].value)
	}
}