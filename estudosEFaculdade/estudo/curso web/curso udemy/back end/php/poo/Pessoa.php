<?php
	class Pessoa{
		/*public $nome; //public define como uma variavel publica.*/
		protected $nome;
		const ESPECIE = "Humana";
		
		/*
			//tipos de daods
			public -> pode ser acessado por qualquer pessoa
			private -> pode ser acessado por dentro da classe
			protected -> só pode ser acessado pela classe ou por herança
		*/
		/*//retorna o valor
		public function falarNome(){
			echo $this->nome;//this ==> this(esse atributo ou prop ou campo nome ). diz ao escopo local 
		}*/
		public function __construct($tmpNome){
			$this->nome = $tmpNome; 
		}
		public function setNome($novoNome){
			$this ->nome = $novoNome; // pega a referencia da variavel
		}
		public function getNome(){
			return $this->nome;
		}
	}
