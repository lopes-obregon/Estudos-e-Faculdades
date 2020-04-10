#programa que abre e reproduz um audio
import pygame
pygame.init() #incializa o modulo
pygame.mixer.music.load('camame.mp3')
pygame.mixer.music.play()#incia a musica
pygame.event.wait()#termina assim que terminar o evento no caso a musica

