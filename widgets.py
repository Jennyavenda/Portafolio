import tkinter as tk


root = tk.Tk()
root.title("Verbooos")
root.config(background="grey")

verbo_usuario = tk.StringVar()


def comando_frances():
    frame.destroy()
    frame_frances = tk.Frame(root, background="light grey")
    frame_frances.pack()

    label_frances = tk.Label(frame_frances, text="Verbo:")
    label_frances.pack(side="top")

    entrada_verbo = tk.Entry(frame_frances, textvariable=verbo_usuario)
    entrada_verbo.pack(side="left", pady=20, padx=30)

    boton_frances_buscar = tk.Button(frame_frances, text="Buscar")
    boton_frances_buscar.pack(side="left", pady=20, padx=10, expand=True)

    print("frances")


def comando_aleman():
    frame.destroy()
    frame_aleman = tk.Frame(root, background="light grey")
    frame_aleman.pack()

    label_aleman = tk.Label(frame_aleman, text="Verbo:")
    label_aleman.pack(side="top")

    entrada_verbo = tk.Entry(frame_aleman, textvariable=verbo_usuario)
    entrada_verbo.pack(side="top", pady=20, padx=30)

    label_aleman2 = tk.Label(frame_aleman, text="Tiempo:")
    label_aleman2.pack(side="top")

    boton_aleman_infinitivo = tk.Button(frame_aleman, text="Infinitivo")
    boton_aleman_infinitivo.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_preterito = tk.Button(frame_aleman, text="Pretérito")
    boton_aleman_preterito.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_pasadoperf = tk.Button(frame_aleman, text="Pasado")
    boton_aleman_pasadoperf.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_todos = tk.Button(frame_aleman, text="Todos")
    boton_aleman_todos.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_buscar = tk.Button(frame_aleman, text="Buscar")
    boton_aleman_buscar.pack(side="bottom", pady=50, padx=50, expand=True)


frame = tk.Frame(root, background="grey")
frame.pack()

label = tk.Label(frame, text="¿A qué idioma deseas traducir tu verbo?", background="white")
label.pack(side="top")
label.config(font=("Ayuthaya", 20))

boton_frances = tk.Button(frame, text="Francés", command=comando_frances)
boton_frances.pack(side="left", pady=20, padx=50, expand=True)

boton_aleman = tk.Button(frame, text="Alemán", command=comando_aleman)
boton_aleman.pack(side="left", pady=20, padx=50, expand=True)

boton_adios = tk.Button(frame, text="Cancelar", command=root.destroy)
boton_adios.pack(side="right", pady=20, padx=50, expand=True)


print(verbo_usuario)

root.mainloop()
