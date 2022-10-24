from cryptography import CeaserCipher
from widgets import getname, namegrande, scroll, otros
from Firebase  import entradaFirebase, salidaFirebase
import tkinter as tk
import time

#Jennifer Avendaño Sánchez      A01656951

root= tk.Tk()
root.title("Chat")
root.geometry("500x500")
root.config(background = "light blue")

def borrar():
  name = chat_final.name
  chat_final.destroy()
  nombre = namegrande(root, name)
  nombre.pack()
  empaquetado = scroll(root, name)
  empaquetado.pack()
  botones = otros(root,Send,Pull)
  botones.pack()
  

def Send(message):#muestra el mensaje
  print(message.get())
  empaquetado.add_message(message)
  message.set("")
  entradaFirebase(message, name)

def Pull(name): #deja ver los anteriores mensajes
  salidaFirebase(name)

chat_final = getname(root, borrar)
chat_final.pack()

name = chat_final.name
#nombre = namegrande(root, name)
#nombre.pack(fill = "x")
#nombre.forget()
empaquetado = scroll(root, name)
empaquetado.pack()
#empaquetado.pack()
#botones = otros(root,Send,Pull)
#botones.pack()
#botones.forget()


root.mainloop()
