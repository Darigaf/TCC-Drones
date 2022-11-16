import pygame
import pygame.image
from PIL import Image
import cv2
import time
import KeyPressModule as kp

kp.init()

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

            if mouse_is_pressed[0]:
                #self.comando()
                self.image.fill(color_pressed)
                print("pressao")
                return True
            else:
                self.image.fill(color_unpressed)
                return False
        else:
            self.image.fill((255,255,0))

pygame.init()

tamanho_tela = (720, 720)

tela = pygame.display.set_mode(tamanho_tela)

webcam = cv2.VideoCapture(0)

color_bg = (255,255,255)

color_pressed = (100,100,100)
color_unpressed = (170,170,170)
x = 0
def testando():
    print("funcionaaa")
    global x
    x = 50


while True:
    pygame.event.get()
    mouse = pygame.mouse.get_pos()
    mouse_is_pressed = pygame.mouse.get_pressed()

    print(mouse)
    print(mouse_is_pressed)

    img = cv2.cvtColor(webcam.read()[1],cv2.COLOR_BGR2RGB)
    img = cv2.resize(img, tamanho_tela)
    imagem = Image.fromarray(img)
    img_mode = imagem.mode

    py_img = pygame.image.frombuffer(img.tostring(), img.shape[1::-1], "RGB")
    tela.blit(py_img, ((tamanho_tela[0]/6),0))
    pygame.display.flip()
    pos1 = (100, 600)
    pos2 = (600, 600)
    cor = (255,255,0)

    botao_w = Button("w", (pos1), 40, (cor), ())
    pos1 = (pos1[0] - 26), (pos1[1] + 45)
    botao_a = Button("a", (pos1), 40, (cor), (lambda: print("a")))
    pos1 = (pos1[0] + 30), pos1[1]
    botao_s = Button("s", (pos1), 40, (cor), (lambda: print("s")))
    pos1 = (pos1[0] + 28), pos1[1]
    botao_d = Button("d", (pos1), 40, (cor), (lambda: print("d")))

    botao_cima = Button("↑", (pos2), 40, (cor), (lambda: print("↑")))
    pos2 = (pos2[0] - 45), (pos2[1] + 52)
    botao_esquerda = Button("←", (pos2), 40, (cor), (lambda: print("←")))
    pos2 = (pos2[0] + 45), pos2[1]
    botao_baixo = Button("↓", (pos2), 40, (cor), (lambda: print("↓")))
    pos2 = (pos2[0] + 30), pos2[1]
    botao_direita = Button("→", (pos2), 40, (cor), (lambda: print("→")))

    print(botao_w.hover_effect())

    if kp.getKey("w") or botao_w.hover_effect():
        print("top")
    
    botao_w.blit()
    botao_a.blit()
    botao_s.blit()
    botao_d.blit()

    botao_cima.blit()
    botao_esquerda.blit()
    botao_baixo.blit()
    botao_direita.blit()

    pygame.display.update()

    ls = 0
    
