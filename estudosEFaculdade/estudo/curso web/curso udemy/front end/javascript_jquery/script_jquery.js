//$(seletor).ação();
/*$(document).ready(function(){
	//verificar se o botão foi clicado
	$('#azul').click(function(){
		$('p').css("background-color", "blue")
		//$('p').fadeOut()
	});
	$('#vermelho').click(function(){
		$('p').css("background-color", "red");
		/*$('p').fadeOut('slow');
		$('p').delay(3000);
		$('p').fadeIn(5000);*/
		/*$('#mensagem').text("Cor alterada com sucesso")
			.css({color:'red', border:'1px solid red'})
			.delay(3000)
			.fadeOut('fast')
			.addClass('green')

		$('button').removeClass('red');
	})
});*/
$(function(){
	$('#l1').click(function(){
		$('#i1').show();
		$('#i2').hide();
		$('#i3').hide();
			
	});
	$('#l2').click(function(){
		$('#i1').hide();
		$('#i2').show();
		$('#i3').hide();	
	});
	$('#l3').click(function(){
		$('#i1').hide();
		$('#i2').hide();
		$('#i3').show();	
	})
})