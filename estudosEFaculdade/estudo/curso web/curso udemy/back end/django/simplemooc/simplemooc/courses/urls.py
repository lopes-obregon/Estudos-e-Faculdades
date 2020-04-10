
from django.urls import path, include
from simplemooc.courses import views
urlpatterns = [
    path('',views.courses, name='index'),
    
]