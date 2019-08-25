#Jacob Hunter Tessman
#main.py 
#Last updated 5-28-19

from tkinter import *
from PIL import ImageTk, Image

class Window(Frame):
    def __init__(self, master = None):
        Frame.__init__(self, master)
        self.master = master
        self.init_window()


    def init_window(self):
        self.master.title("Little Brother")
        self.pack(fill=BOTH, expand=1)
        
        canvas= Canvas(self, width = 1200, height = 1200)
        cctv = PhotoImage(file = "CCTV.png")
        canvas.create_image(0, 0, image = cctv)

        self.configure(background='black')
        v = StringVar()
        v.set("Hello, world!")
        w = Label(root, pady = 600, textvariable = v)
        w.pack()
        
        menu = Menu(self.master)
        self.master.config(menu=menu)
        file_m = Menu(menu)

        file_m.add_command(label='Exit', command=self.client_exit)
        file_m.add_command(label='Save', command=lambda : self.update_labels(v))
        menu.add_cascade(label='File', menu=file_m)

        edit_m = Menu(menu)
        edit_m.add_command(label='Undo')
        menu.add_cascade(label='Edit', menu=edit_m)


    def client_exit(self):
        exit()

    def update_labels(self, var):
        var.set("UPDATED!!!!!")


root = Tk()
root.geometry("2100x1200")
app = Window(root)

root.mainloop()
