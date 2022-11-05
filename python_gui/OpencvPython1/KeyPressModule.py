import pygame


def init():
    pygame.init()
    #win = pygame.display.set_mode((400, 400))
    tamanho_tela = (pygame.display.Info().current_w, pygame.display.Info().current_h)

    screen = pygame.display.set_mode( ( tamanho_tela ) )
    return tamanho_tela


def getKey(keyName):
    ans = False
    for eve in pygame.event.get(): pass
    keyInput = pygame.key.get_pressed()
    myKey = getattr(pygame, 'K_{}'.format(keyName))
    print('K_{}'.format(keyName))

    if keyInput[myKey]:
        ans = True
    pygame.display.update()
    return ans


def main():
    if getKey("LEFT"):
        print("Left key pressed")

    if getKey("RIGHT"):
        print("Right key Pressed")


if __name__ == "__main__":
    init()
    while True:
        main()
