from django.db import models
from django.db.models import Q
# Create your models here.
#classe para gerenciar os cursos
class CouseManger(models.Manager):
	#func para pesquisa
	def search(self, query):#query para fazer consulta
		return self.get_queryset().filter(Q(name=query) |   
		Q(description=query))#representa a listagem dos models
#classe para cadastro de curso no banco de dados
class Course(models.Model):#herda de modls.models
	name = models.CharField('Nome', max_length=100)#para formulario exibição
	slug = models.SlugField('Atalho')
	description = models.TextField('Descrição', blank=True)#mesmo que charfield só que sem tamanho , blank(não obrigatório)
	start_date = models.DateField(
		'Data de Início', null=True, blank=True
		)
	image = models.ImageField(upload_to='courses/images', verbose_name='Imagem', null=True, blank=True) #caminho da imagem que fica no diretório fisico

	crated_at = models.DateTimeField('Criado em', auto_now_add=True)
	updated_at = models.DateTimeField('Atualizado em', auto_now=True)#auto_now toda vez que autalizado ele guarda
	objects = CouseManger()
	def __str__(self):
		return self.name

	class  Meta:
		verbose_name = 'Curso'
		verbose_name_plural = 'Cursos'
		ordering = ['name']