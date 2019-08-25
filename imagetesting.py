from tkinter import *  
from PIL import ImageTk,Image  
root = Tk()  
canvas = Canvas(root, width = 1400, height = 1400)  
canvas.pack()  
img = PhotoImage(Image.open("CCTV.png"))  
scale = 6
img.zoom(scale, scale)
canvas.create_image(20, 20, anchor=NW, image=img) 
root.mainloop()
