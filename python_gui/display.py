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
controler.place(height=100, width=1280, x=0, y=620)
controler_wasd.place(width=248, height=100, x=10, y=10)

#defines wasd buttons
controler_w = ttk.Button(controler_wasd, text='W', width=3)
controler_a = ttk.Button(controler_wasd, text='A', width=3)
controler_s = ttk.Button(controler_wasd, text='S', width=3)
controler_d = ttk.Button(controler_wasd, text='D', width=3)

controler_w.place(x=45, y=00)
controler_a.place(x=10, y=30)
controler_s.place(x=45, y=30)
controler_d.place(x=80, y=30)
#places the wasd buttons on their default layout

controler.lift()

controler_wasd.lift()
controler_w.lift()
controler_a.lift()
controler_s.lift()
controler_d.lift()


#controler_up_down = ttk.Frame(controler)
#controler_land_takeoff = ttk.Frame(controler)
show_video()
root.mainloop()
