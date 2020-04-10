<?php 
	//varaveis
	$mensagem = 'hello world';
	//print
	echo $mensagem;
	//operaçoes
	$a = 2;
	$b = 3;
	$soma = $a + $b;
	echo $soma;
	//** expotenciação
	if ($a % 2 == 0) {
		echo "Numero é par";
	} else {
		echo "Numero é impar";
	}
	#foreach
	#percorre um conjunto de dados
	$i = [0,1,2,3,4,5,6,7,8,9];
	foreach ($i as $j) {
		# code...
		echo $j;#CADA ELEMENTO
	}
 ?>