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
drone.connect()
print(drone.get_battery())
cor = (255,255,0)

tamanho_tela = (pygame.display.Info().current_w, pygame.display.Info().current_h)
command_port = 8889
drone.streamon()
screen = pygame.display.set_mode( ( tamanho_tela ) )

#pygame.camera.init()
#cameras = pygame.camera.list_cameras()
#webcam = pygame.camera.Camera(cameras[0], (tamanho_tela))
#webcam.start()

pygame.event.get()
mouse = pygame.mouse.get_pos()
mouse_is_pressed = pygame.mouse.get_pressed()

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
        screen.blit(self.image, self.posicao)

    def hover_effect(self):
        if self.rect.collidepoint(mouse):
            print("colisao")

            if mouse_is_pressed[0]:
                print("pressão")
                self.comando()
                self.image.fill(cor)
                return true
            else:
                return false
                self.image.fill(cor)
        else:
            self.image.fill((255,255,0))

lr, fb, ud, yv = 0, 0, 0, 0

def esquerda():
    global lf
    lf = -speed
def direita():
    global lf
    lf = speed
def frente():
    global fb
    fb = speed
def tras():
    global fb
    fb = -speed
def cima():
    global ud
    ud = speed
def baixo():
    global ud
    ud = -speed
def yall():
    global yv
    yv = speed
def yallmenos():
    global yv
    yv = -speed

def getKeyboardInput():
    lr, fb, ud, yv = 0, 0, 0, 0
    speed = 45
    if kp.getKey("LEFT") | botao_w.hover_effect() :
        lf = -speed
    elif kp.getKey("RIGHT"):
        direita
    if kp.getKey("UP"):
        fb = speed
    elif kp.getKey("DOWN"):
        fb = -speed
    if kp.getKey("w"):
        ud = speed
    elif kp.getKey("s"):
        ud = -speed
    if kp.getKey("a"):
        yv = -speed
    elif kp.getKey("d"):
        yv = speed
    if kp.getKey("q"):
        drone.land()
        sleep(3)
    if kp.getKey("e"):
        drone.takeoff()
    return [lr, fb, ud, yv]

#webcam = cv2.VideoCapture(0)
pos1 = (100, 600)
pos2 = (600, 600)
cor = (255,255,0)
speed = 45

botao_w = Button("w", (pos1), 40, (cor), (cima))
pos1 = (pos1[0] - 26), (pos1[1] + 45)
botao_a = Button("a", (pos1), 40, (cor), (yallmenos))
pos1 = (pos1[0] + 30), pos1[1]
botao_s = Button("s", (pos1), 40, (cor), (baixo))
pos1 = (pos1[0] + 28), pos1[1]
botao_d = Button("d", (pos1), 40, (cor), (yall))

botao_cima = Button("↑", (pos2), 40, (cor), (frente))
pos2 = (pos2[0] - 45), (pos2[1] + 52)
botao_esquerda = Button("←", (pos2), 40, (cor), (esquerda))
pos2 = (pos2[0] + 45), pos2[1]
botao_baixo = Button("↓", (pos2), 40, (cor), (baixo))
pos2 = (pos2[0] + 30), pos2[1]
botao_direita = Button("→", (pos2), 40, (cor), (direita))

botao_pouso = Button("Pousar", (150, 500), 40, (cor), (lambda: drone.land()))
botao_voo = Button("Tomar vôo", (1000, 500), 40, (cor), (lambda: drone.takeoff()))

while True:
    vels = getKeyboardInput()
    pygame.event.get()
    mouse = pygame.mouse.get_pos()
    mouse_is_pressed = pygame.mouse.get_pressed()

    img = drone.get_frame_read().frame
    #img = cv2.cvtColor(webcam.read()[1],cv2.COLOR_BGR2RGB)
    img = cv2.resize(img, tamanho_tela)
    #img = webcam.get_image()
    imagem = Image.fromarray(img)
    modo = imagem.mode
    py_img = pygame.image.frombuffer(img.tostring(), img.shape[1::-1], "BGR")
    screen.blit(py_img, ((tamanho_tela[0]/6),0))
    pygame.display.flip()


    

#   botao_w = Button("w", (pos1), 40, (cor), (cima))
#   pos1 = (pos1[0] - 26), (pos1[1] + 45)
#   botao_a = Button("a", (pos1), 40, (cor), (yallmenos))
#   pos1 = (pos1[0] + 30), pos1[1]
#   botao_s = Button("s", (pos1), 40, (cor), (baixo))
#   pos1 = (pos1[0] + 28), pos1[1]
#   botao_d = Button("d", (pos1), 40, (cor), (yall))

#   botao_cima = Button("↑", (pos2), 40, (cor), (frente))
#   pos2 = (pos2[0] - 45), (pos2[1] + 52)
#   botao_esquerda = Button("←", (pos2), 40, (cor), (esquerda))
#   pos2 = (pos2[0] + 45), pos2[1]
#   botao_baixo = Button("↓", (pos2), 40, (cor), (baixo))
#   pos2 = (pos2[0] + 30), pos2[1]
#   botao_direita = Button("→", (pos2), 40, (cor), (direita))

#   botao_pouso = Button("Pousar", (150, 500), 40, (cor), (lambda: drone.land()))
#   botao_voo = Button("Tomar vôo", (1000, 500), 40, (cor), (lambda: drone.takeoff()))

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
    
    pygame.display.update()

    #vels = getKeyboardInput()
    drone.send_rc_control(vels[0], vels[1], vels[2], vels[3])
    sleep(0.05)
    lr, fb, ud, yv = 0, 0, 0, 0

