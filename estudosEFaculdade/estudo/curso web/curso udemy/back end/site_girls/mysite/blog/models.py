from django.db import models
from django.utils import timezone


class Post(models.Model):#defiene a classe e diz que será um modelo django que será salvo no banco de dados
    author = models.ForeignKey('auth.User', on_delete=models.CASCADE)
    title = models.CharField(max_length=200)#define um texto com um numéro limitado de cracteres
    text = models.TextField()#define um texto sem limites de  caracter
    created_date = models.DateTimeField(
            default=timezone.now)#define a data e hora
    published_date = models.DateTimeField(
            blank=True, null=True)

    def publish(self):
        self.published_date = timezone.now()
        self.save()

    def __str__(self):
        return self.title