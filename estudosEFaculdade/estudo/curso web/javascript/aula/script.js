//confirm("Olá obrigado por utilizar o meu programa :D") //janela com o botã ok e cancelar
/*var nome =prompt("Qual o seu nome?")//vai a pergunta o nome
var idade = prompt("Qual a Sua idade?")
alert("Olá " + nome + ", sua idade é de " + idade + " idade")//printf do c ou print do python*/
//convertendo string para números
/*var n1 = prompt("Digite um número: ")
var n2 = prompt("Digite outro número")
//convertendo para inteiro
n1 = parseInt(n1)
n2 = parseInt(n2)
alert("Seu número convertido para inteiro é: " + (n1 + n2))
//convertendo para float
n1 = parseFloat(n1)
n2 = parseFloat(n2)
alert("Seu número convertido para float é: " + (n1 + n2))
//convertendo automatico
n1 = Number(n1)
n2 = Number(n2)
alert("Seu número: " + (n1 + n2))
//convertendo em string
n1 = String(n1)*/
//array
/*let num = [5, 8, 4]
num[3] = 6 //adiciona valor
num.push(7)//adiciona na ultima posição
console.log(num)
console.log(`Tamanho do vector ${num.length}`)
num.sort()//ordena em ordem crescente
console.log(`The new vector ${num}`)
for (let pos in num) {
	console.log(`valor: ${num[pos]}`)
}
//buscando valor
console.log(num.indexOf(7))*/
//funções
/*function fatorial(n){
	let fat = 1
	for(let i = n; i > 1; i--){
		fat *= i
	}
	return fat
}*/
//recursiva
function fatorial(n){
	if(n == 1){
		return 1
	}else{
		return n * fatorial(n - 1)
	}
}
console.log(fatorial(5))