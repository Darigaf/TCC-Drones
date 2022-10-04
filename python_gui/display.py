from tkinter import *
from tkinter import ttk

#creates the screen and puts the text in the title
root = Tk()
root.title("Sentinelas")
root.geometry("1280x720")

#creates the main frame, that will contain all other aplications widgets, and set it's size to 1280x720
mainframe = ttk.Frame(root, padding="3 3 12 12")
mainframe.pack(fill="both")
#places the mainframe on the screen grid
#mainframe.grid(column=0, row=0)
#mainframe.columnconfigure(0, weight=10)
#mainframe.rowconfigure(0, weight=10)

#creates the camera frame, the plan is to display the live tello camera on it
#camera = ttk.Frame(mainframe, width=1280, height=720)

controler = ttk.Frame(mainframe, height=72)
controler_wasd = ttk.Frame(controler)

#controler.grid(column=0, row=1, sticky=(S))
controler.pack(side="bottom", fill=X)
#controler.rowconfigure(0, weight=5)
#controler.columnconfigure(0, weight=5)

#controler_wasd.grid(column=0, row=1, sticky=(S, W))
controler_wasd.pack(side="left")
#controler_wasd.rowconfigure(0)
#controler_wasd.columnconfigure(0)

#defines wasd buttons
controler_w = ttk.Button(controler_wasd, text='W')
controler_a = ttk.Button(controler_wasd, text='A')
controler_s = ttk.Button(controler_wasd, text='S')
controler_d = ttk.Button(controler_wasd, text='D')

controler_w.pack(anchor="n")
controler_a.pack(anchor="sw")
controler_s.pack(anchor="s")
controler_d.pack(anchor="se")


#places the wasd buttons on their default layout
#controler_w.grid(column=1, row=0)
#controler_a.grid(column=0, row=1)
#controler_s.grid(column=1, row=1)
#controler_d.grid(column=2, row=1)

#controler_up_down = ttk.Frame(controler)
#controler_land_takeoff = ttk.Frame(controler)
root.mainloop()
