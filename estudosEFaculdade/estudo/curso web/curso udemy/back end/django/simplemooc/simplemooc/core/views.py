from django.shortcuts import render#renderizaa o template
from django.http import HttpResponse#sempre deve retornar isso para o django entender oque será sua resposta
# Create your views here.
#criei a função home
def home(request):
	return render(request, 'home.html')

def contact(request):
	return render(request, 'contact.html')