from chatterbot.trainers import ListTrainer
from gtts import gTTS
from chatterbot import ChatBot
from playsound import playsound
import os
#função que cria o audio
def cria_audio(audio):
	tts = gTTS(audio, lang='pt-br')#define o tipo de audio
	tts.save('talkTest.mp3') #salva o audio
	print("system: Carregando...")
	playsound('talkTest.mp3')#reproduz o audio
	print("system: Removendo arquivo de audio")
	os.remove('talkTest.mp3')
	print("system: arquivo de audio removido")
#main
if __name__ == '__main__':
	cria_audio("Seja bem vindo, Ao assistente de teste.")
	bot = ChatBot('Assistente De Teste Bot')#define o construtor
	cria_audio("Carregando Sistema")
	conversa = ['oi', 'Olá!', 'tudo bem?' , 'tudo ótimo!', 'você gosta de programar?', 'sim, eu programar em Python!', 'como você esta?', 'estou bem, obrigada por perguntar!'] #define as conversas
	comandos = ['desativar','Desativando!']
	trainer = ListTrainer(bot)
	#train como ponto de partida e foi utlizado a lista conversa com partida na aprendizagem
	trainer.train(conversa)
	trainer.train(comandos)
	cria_audio("Sistema pronto e operando em cem porcento.")
	#definir que o grau de confiança da resposta for menor que 0.5 o bot vai informar que a inda não sabe a resposta de tal pergunta:
	while True:
		pergunta = input("Usuário: ")
		#resposta = bot.get_response(pergunta)
		resposta = bot.get_response(pergunta)
		if float(resposta.confidence) > 0.5:
			print("Assistente De Teste: ", resposta)
			cria_audio(str(resposta))
			if(pergunta == 'desativar'): 
				break
		else:
			print("Assistente De Teste: Ainda não sei responder esta pergunta")		
			resposta = 'Ainda não sei responder esta pergunta'
			cria_audio(str(resposta))