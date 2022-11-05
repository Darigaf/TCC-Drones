import pygame
import pygame.image
from PIL import Image
import cv2
import time

pygame.init()

tamanho_tela = (720, 720)

tela = pygame.display.set_mode(tamanho_tela)

webcam = cv2.VideoCapture(1)


class Button:
    def __init__(self, texto, posicao, tamanho, cor, comando):
        self.texto = texto
        self.x, self.y = posicao
        self.posicao = posicao
        self.tamanho = tamanho
        self.cor = cor
        self.comando = comando
        self.criar_botao()

    def criar_botao(self):
        self.fonte = pygame.font.SysFont("Arial", self.tamanho)
        self.txt = self.fonte.render(self.texto, 1, (0,0,0))
        txt_w, txt_h = self.txt.get_size()
        self.rect = pygame.Rect(self.x, self.y, txt_w, txt_h)
        self.image = pygame.Surface((txt_w, txt_h))
        self.image.fill(self.cor)
        self.image.blit(self.txt, (0,0))

    def blit(self):
        self.hover_effect()
        self.image.blit(self.txt, (0,0))
        tela.blit(self.image, self.posicao)

    def hover_effect(self):
        if self.rect.collidepoint(mouse): 
            print("colisao")

            for event in pygame.event.get():
                if event.type == pygame.MOUSEBUTTONDOWN:
                    self.comando()
                    self.image.fill(color_pressed)
                    time.sleep(0.1)
                else:
                    self.image.fill(color_unpressed)
        else:
            self.image.fill((255,255,0))

pygame.init()

tamanho_tela = (720, 720)

tela = pygame.display.set_mode(tamanho_tela)

webcam = cv2.VideoCapture(0)

color_bg = (255,255,255)

color_pressed = (100,100,100)
color_unpressed = (170,170,170)


while True:
    pygame.event.get()
    mouse = pygame.mouse.get_pos()
    print(mouse)
    bota_1 = Button("w", (100, 100), 40, (255,255,0), (lambda: print("hello")))

    img = cv2.cvtColor(webcam.read()[1],cv2.COLOR_BGR2RGB)
    img = cv2.resize(img, tamanho_tela)
    imagem = Image.fromarray(img)
    img_mode = imagem.mode

    py_img = pygame.image.frombuffer(img.tostring(), img.shape[1::-1], "RGB")
    tela.blit(py_img, ((tamanho_tela[0]/6),0))
    pygame.display.flip()

    bota_1.blit()
    pygame.display.update()


