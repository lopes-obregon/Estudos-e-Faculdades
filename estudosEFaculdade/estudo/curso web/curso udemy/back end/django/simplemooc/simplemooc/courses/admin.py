from django.contrib import admin
from .models import Course#importa o models que queremos cadastrar
# Register your models here.
#Representa as opções do curso
class CourseAdmin(admin.ModelAdmin):
	list_display = ['name', 'slug', 'start_date', 'crated_at']
	#definir opções para editar o admin
	search_fields = ['name', 'slug']
	prepopulated_fields = {'slug': ('name',)}
#main
admin.site.register(Course, CourseAdmin)
