from djitellopy import tello
import cv2

me = tello.Tello()
me.connect()
print(me.get_battery())

command_port = 8889
me.streamon()

while True:
    img = me.get_frame_read().frame
    img = cv2.resize(img, (800, 600))
    cv2.imshow("Image", img)
    cv2.waitKey(1)
