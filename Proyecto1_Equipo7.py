
def pies(entrada):
    if entrada >= 0:
        resultado=(entrada * 2.54)
        print(resultado)
    else:
        print("error")

def pulgada(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 39.37)
        print(resultado)
    else:
        print("error")
        
def yarda(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 1.094)
        print(resultado)
    else:
        print("error")
        
def rod(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 0.198839)
        print(resultado)
    else:
        print("error")

def cadenas(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 20,1168)
        print(resultado)
    else:
        print("error")
def millas(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 0.000621371)
        print(resultado)
    else:
        print("error")

def mm(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 1000)
        print(resultado)
    else:
        print("error")
        
def cm(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) * 100)
        print(resultado)
    else:
        print("error")
        
def km(entrada):
    if entrada >= 0:
        resultado=(var.get(entrada) / 1000)
        print(resultado)
    else:
        print("error")
        
            #pies, pulgadas, yardas, rod, cadena, millas, mm, cm y Km
import tkinter as tk
root = tk.Tk()
root.geometry('600x400')

entrada= tk.StringVar()
var= tk.DoubleVar()
var= tk.Entry(root, width=28, textvariable=entrada, bg='black', fg='green')
var.grid (row = 0, column=1, ipadx=30, ipady=20, sticky='nsew')
var.get()
var.focus()

pulga = tk.Button(root, text='pulgadas', bg='white', fg='black', command=pulgada)
pulga.grid(row=1, column=0, ipadx=10, ipady=15)

pie = tk.Button(root, text='pies', bg='white', fg='black', command=pies)
pie.grid(row=1, column=1, ipadx=10, ipady=15)

yarda = tk.Button(root, text='yarda', bg='white', fg='black', command=yarda)
yarda.grid(row=1, column=2, ipadx=10, ipady=15)

rod = tk.Button(root, text='rod', bg='white', fg='black', command=rod)
rod.grid(row=2, column=0, ipadx=10, ipady=15)

cadena = tk.Button(root, text='cadena', bg='white', fg='black', command=cadenas)
cadena.grid(row=2, column=1, ipadx=10, ipady=15)

milla = tk.Button(root, text='milla', bg='white', fg='black', command=millas)
milla.grid(row=2, column=2, ipadx=10, ipady=15)

mm = tk.Button(root, text='mm', bg='white', fg='black', command= mm)
mm.grid(row=3, column=0, ipadx=10, ipady=15)

cm = tk.Button(root, text='cm', bg='white', fg='black', command=cm)
cm.grid(row=3, column=1, ipadx=10, ipady=15)

km = tk.Button(root, text='km', bg='white', fg='black', command=km)
km.grid(row=3, column=2, ipadx=10, ipady=15)
root.mainloop()
