from djitellopy import tello
from PIL import Image
import pygame
import pygame.camera
import pygame.image
import KeyPressModule as kp
from time import sleep
import cv2

kp.init()
drone = tello.Tello()
#drone.connect()
cor_unpressed = (201,221,255)
cor_pressed = (141,141,255)
cor_botao = cor_unpressed

tamanho_tela = (pygame.display.Info().current_w, pygame.display.Info().current_h)
command_port = 8889
#drone.streamon()
screen = pygame.display.set_mode( ( tamanho_tela ) )


def get_mouse_pressed():
    global mouse_is_pressed
    global mouse
    pygame.event.get
    mouse = pygame.mouse.get_pos()
    mouse_is_pressed = pygame.mouse.get_pressed()


class Button:
    def __init__(self, texto, posicao, tamanho):
        self.texto = texto
        self.x, self.y = posicao
        self.posicao = posicao
        self.tamanho = tamanho
        self.criar_botao()

    def criar_botao(self):
        self.fonte = pygame.font.SysFont("Arial", self.tamanho)
        self.txt = self.fonte.render(self.texto, 1, (0,0,0))
        txt_w, txt_h = self.txt.get_size()
        self.rect = pygame.Rect(self.x, self.y, txt_w, txt_h)
        self.image = pygame.Surface((txt_w, txt_h))
        self.image.fill(cor_unpressed)
        self.image.blit(self.txt, (0,0))

    def blit(self):
        self.hover_effect()
        self.image.blit(self.txt, (0,0))
        screen.blit(self.image, self.posicao)
    def color_change(self):
        self.image.fill(cor_botao)

    def pressed(self):
        if mouse_is_pressed[0]:
            print("pressão")
            cor_botao = cor_pressed
            self.image.fill(cor_pressed)
            return True
        else:
            cor_botao = cor_unpressed
            self.image.fill(cor_unpressed)
            return False
            
    def hover_effect(self):
        get_mouse_pressed()
        if self.rect.collidepoint(mouse):
            print("colisao")
            self.pressed()
        else:
            cor_botao = cor_unpressed
            self.color_change
def unpress_buttons():
    botao_esquerda.image.fill(cor_unpressed)
    botao_direita.image.fill(cor_unpressed)
    botao_cima.image.fill(cor_unpressed)
    botao_baixo.image.fill(cor_unpressed)
    botao_w.image.fill(cor_unpressed)
    botao_a.image.fill(cor_unpressed)
    botao_s.image.fill(cor_unpressed)
    botao_d.image.fill(cor_unpressed)
    botao_voo.image.fill(cor_unpressed)
    botao_pouso.image.fill(cor_unpressed)

def getKeyboardInput():
    lr, fb, ud, yv = 0, 0, 0, 0
    speed = 45
    if ~(pygame.key.get_focused()):
        unpress_buttons()
    if kp.getKey("LEFT") or botao_esquerda.hover_effect():
        lr = -speed
        botao_esquerda.image.fill(cor_pressed)
    elif kp.getKey("RIGHT") or botao_direita.hover_effect():
        lr = speed 
        botao_direita.image.fill(cor_pressed)
    if kp.getKey("UP") or botao_cima.hover_effect():
        fb = speed
        botao_cima.image.fill(cor_pressed)
    elif kp.getKey("DOWN") or botao_baixo.hover_effect():
        fb = -speed
        botao_baixo.image.fill(cor_pressed)
    if kp.getKey("w") or botao_w.hover_effect():
        ud = speed
        botao_w.image.fill(cor_pressed)
    elif kp.getKey("s") or botao_s.hover_effect():
        ud = -speed
        botao_s.image.fill(cor_pressed)
    if kp.getKey("a") or botao_a.hover_effect():
        yv = -speed
        botao_a.image.fill(cor_pressed)
    elif kp.getKey("d") or botao_d.hover_effect():
        yv = speed
        botao_d.image.fill(cor_pressed)
    if kp.getKey("q") or botao_pouso.hover_effect():
        drone.land()
        botao_pouso.image.fill(cor_pressed)
        sleep(3)
    if kp.getKey("e") or botao_voo.hover_effect():
        botao_voo.image.fill(cor_pressed)
        drone.takeoff()
    return [lr, fb, ud, yv]

webcam = cv2.VideoCapture(0)
pos1 = (15*(tamanho_tela[0]/100)), (75*(tamanho_tela[1]/100))


#pos1 = (200, 580)
#pos2 = (1150, 580)
pos2 = (85*(tamanho_tela[0]/100)), (75*(tamanho_tela[1]/100))
speed = 45

botao_w = Button("w", (pos1), 40)
pos1 = (pos1[0] - 26), (pos1[1] + 45)
botao_a = Button("a", (pos1), 40)
pos1 = (pos1[0] + 30), pos1[1]
botao_s = Button("s", (pos1), 40)
pos1 = (pos1[0] + 28), pos1[1]
botao_d = Button("d", (pos1), 40)

botao_cima = Button("↑", (pos2), 40)
pos2 = (pos2[0] - 45), (pos2[1] + 52)
botao_esquerda = Button("←", (pos2), 40)
pos2 = (pos2[0] + 45), pos2[1]
botao_baixo = Button("↓", (pos2), 40)
pos2 = (pos2[0] + 30), pos2[1]
botao_direita = Button("→", (pos2), 40)

botao_pouso = Button("Pousar", (12*(tamanho_tela[0]/100), 67*(tamanho_tela[1]/100)), 40)
botao_voo = Button("Tomar vôo", (79*(tamanho_tela[0]/100), 67*(tamanho_tela[1]/100)), 40)

bateria_porcentagem = 0
def bateria_print_percentage(bateria):
    bateria_porcentagem = bateria
    fonte = pygame.font.SysFont("Arial", 40)
    bateria_cor = ((round(255-(bateria_porcentagem*2.55))),(round(bateria_porcentagem*2.55)),0)
    bateria = fonte.render((str(bateria_porcentagem) + "%"), True, bateria_cor)
    screen.blit(bateria, (210,10))
    pygame.draw.ellipse(screen, (245,245,245), [186, 15, 15, 26], 0) 
    pygame.draw.rect(screen, (245,245,245), (86, 10, 108, 36))
    pygame.draw.rect(screen, (bateria_cor), (90, 13, bateria_porcentagem, 30))

def show_drone_camera():
    #img = drone.get_frame_read().frame
    img = webcam.read()[1]
    img_resized = cv2.resize(img, tamanho_tela)
    imagem = Image.fromarray(img_resized)
    py_img = pygame.image.frombuffer(img_resized.tostring(), img_resized.shape[1::-1], "BGR")
    screen.blit(py_img, ((tamanho_tela[0]/6),0))
    pygame.display.flip()

while True:

    #bateria_porcentagem = bateria_porcentagem + 1
    #bateria_porcentagem = drone.get_battery()

    show_drone_camera()

    botao_pouso.blit()
    botao_voo.blit()
    botao_w.blit()
    botao_a.blit()
    botao_s.blit()
    botao_d.blit()

    botao_cima.blit()
    botao_esquerda.blit()
    botao_baixo.blit()
    botao_direita.blit()

    pygame.draw.rect(screen, (0,0,0), (0, 0, tamanho_tela[0], 50))
    bateria_print_percentage(bateria_porcentagem)
    pygame.display.update()

    get_mouse_pressed()

    vels = getKeyboardInput()

    drone.send_rc_control(vels[0], vels[1], vels[2], vels[3])
    sleep(0.005)

