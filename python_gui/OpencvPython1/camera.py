from djitellopy import tello
from PIL import Image
import pygame
import pygame.camera
import pygame.image
import KeyPressModule as kp
from time import sleep
import cv2

kp.init()
#drone = tello.Tello()
#drone.connect()
#print(drone.get_battery())

tamanho_tela = (pygame.display.Info().current_w, pygame.display.Info().current_h)
#command_port = 8889
#drone.streamon()
screen = pygame.display.set_mode( ( tamanho_tela ) )

#pygame.camera.init()
#cameras = pygame.camera.list_cameras()
#webcam = pygame.camera.Camera(cameras[0], (tamanho_tela))
#webcam.start()

def getKeyboardInput():
    lr, fb, ud, yv = 0, 0, 0, 0
    speed = 45
    if kp.getKey("LEFT"):
        lr = -speed
    elif kp.getKey("RIGHT"):
        lr = speed
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

webcam = cv2.VideoCapture(0)

while True:
    #img = drone.get_frame_read().frame
    img = cv2.cvtColor(webcam.read()[1],cv2.COLOR_BGR2RGB)
    img = cv2.resize(img, tamanho_tela)
    #img = webcam.get_image()
    imagem = Image.fromarray(img)
    modo = imagem.mode
    py_img = pygame.image.frombuffer(img.tostring(), img.shape[1::-1], "RGB")
    screen.blit(py_img, ((tamanho_tela[0]/6),0))
    pygame.display.flip()


    vels = getKeyboardInput()
    #drone.send_rc_control(vels[0], vels[1], vels[2], vels[3])
    sleep(0.05)

