from tkinter import *
from tkinter import ttk

#creates the screen and puts the text in the title
root = Tk()
root.title("Sentinelas")

#creates the main frame, that will contain all other aplications widgets, and set it's size to 1280x720
mainframe = ttk.Frame(root, padding="3 3 12 12", width=1280, height=720)
#places the mainframe on the screen grid
mainframe.grid(column=0, row=0)

#creates the camera frame, the plan is to display the live tello camera on it
camera = ttk.Frame(mainframe, width=1280, height=720)

controler = ttk.Frame(mainframe)
controler_wasd = ttk.Frame(controler)
controler_w = ttk.Button(controler_wasd, text='W')
controler_a = ttk.Button(controler_wasd, text='A')
controler_s = ttk.Button(controler_wasd, text='S')
controler_d = ttk.Button(controler_wasd, text='D')
controler_up_down = ttk.Frame(controler)
controler_land_takeoff = ttk.Frame(controler)
controler.grid(column=0, row=5)
controler_wasd.grid(column=1, row=5)
controler_w.grid(column=1, row=5)
controler_a.grid(column=0, row=6)
controler_s.grid(column=1, row=6)
controler_d.grid(column=2, row=6)
root.mainloop()
