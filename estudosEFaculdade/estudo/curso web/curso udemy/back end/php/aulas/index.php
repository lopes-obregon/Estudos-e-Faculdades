<?php 
	$pagina = 'home';
	if(isset($_GET['pagina'])){
		$pagina = $_GET['pagina']
	}
	/*carrega o header.php*/
	include 'header.php';
	//carrega a página escolhida pelo usuário
	switch ($pagina) {
		case 'equipe':
			include 'equipe.php';
			break;
		
		default:
			# code...
			include 'app/views/home.php';
			break;
	}
	//carrega o footer.php
	include 'footer.php';
?>