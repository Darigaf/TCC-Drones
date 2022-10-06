#from tkinter import Tk, Label, Pack
from tkinter import *
from tkinter import ttk
from PIL import ImageTk, Image
#import PIL
import cv2

#creates the screen and puts the text in the title
root = Tk()
root.title("Sentinelas")
root.geometry("1280x720")

#creates the main frame, that will contain all other aplications widgets, and set it's size to 1280x720
mainframe = ttk.Frame(root, padding="3 3 12 12")
mainframe.pack()
#places the mainframe on the screen grid
#mainframe.grid(column=0, row=0)
#mainframe.columnconfigure(0, weight=10)
#mainframe.rowconfigure(0, weight=10)

camera_drone = Label(mainframe)
video = cv2.VideoCapture(0)
video_size = (1280, 720)
def show_video():
    camera = cv2.cvtColor(video.read()[1],cv2.COLOR_BGR2RGB)
    camera = cv2.resize(camera, video_size)
    imagem = Image.fromarray(camera)
    imgtk = ImageTk.PhotoImage(image = imagem)
    camera_drone.imgtk = imgtk
    camera_drone.configure(image=imgtk)
    camera_drone.after(20, show_video)


#creates the camera frame, the plan is to display the live tello camera on it
#camera = ttk.Frame(mainframe, width=1280, height=720)

camera_drone.pack()
controler = ttk.Frame(mainframe, height=72)
controler_wasd = ttk.Frame(controler)

#controler.grid(column=0, row=1, sticky=(S))
controler.pack(side=BOTTOM)
#controler.rowconfigure(0, weight=5)
#controler.columnconfigure(0, weight=5)

#controler_wasd.grid(column=0, row=1, sticky=(S, W))
controler_wasd.pack(side=LEFT)
#controler_wasd.rowconfigure(0)
#controler_wasd.columnconfigure(0)

#defines wasd buttons
controler_w = ttk.Button(controler_wasd, text='W')
controler_a = ttk.Button(controler_wasd, text='A')
controler_s = ttk.Button(controler_wasd, text='S')
controler_d = ttk.Button(controler_wasd, text='D')

controler_w.pack()
controler_a.pack()
controler_s.pack()
controler_d.pack()


#places the wasd buttons on their default layout
#controler_w.grid(column=1, row=0)
#controler_a.grid(column=0, row=1)
#controler_s.grid(column=1, row=1)
#controler_d.grid(column=2, row=1)

#controler_up_down = ttk.Frame(controler)
#controler_land_takeoff = ttk.Frame(controler)
show_video()
root.mainloop()
