<?php 
	if(isset($_POST('submit'))){
		if (isset($_FILES['arquivo'])) {
				# code...
				if (move_uploaded_file($_FILES['arquivo']['tmp_name'], 'data.txt')) {
					# code...
					echo "arquivo enviado com sucesso.";
				}else{
					echo "falhou.";
				}
			}	
	}
?>