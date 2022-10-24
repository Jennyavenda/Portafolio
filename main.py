from webscrapping import alemanmatrix_results, francesmatrix_results
import numpy as np
import tkinter as tk

# Aleman
csv_data_aleman = np.array(alemanmatrix_results)
np.savetxt('verbosalemán.csv', csv_data_aleman, delimiter=',', fmt='%s')

# Francés
csv_data_frances = np.array(francesmatrix_results)
np.savetxt('verbosfrancés.csv', francesmatrix_results, delimiter=',', fmt='%s')

# Interfaz
root = tk.Tk()
root.title("Verbooos")
root.config(background="white")
palabra = tk.StringVar()


def comando_frances():
    frame.destroy()

    def verboinf():
        try:
            framefinal = tk.Frame(root, background="white")
            framefinal.pack()

            buscar_frances = np.where(csv_data_frances == palabra.get())
            traduccion_frances = csv_data_frances[buscar_frances[0], 0]
            traduccion = traduccion_frances[0]
            print(traduccion)

            label_francesverbo = tk.Label(framefinal, text="Verbo en francés:")
            label_francesverbo.pack(side="top")
            label_francesverbo.config(font=("Corbel", 15))

            label_francesverbofinal = tk.Label(framefinal, text=traduccion)
            label_francesverbofinal.pack(side="top")
            label_francesverbofinal.config(font=("Corbel", 15))

        except:
            label_francesverbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_francesverbo.pack(side="top")
            label_francesverbo.config(font=("Corbel", 15))

            print("Verbo no encontrado")

    frame_frances = tk.Frame(root, background="white")
    frame_frances.pack()

    label_frances = tk.Label(frame_frances, text="Verbo:")
    label_frances.pack(side="top")
    label_frances.config(font=("Corbel", 15))

    entrada_verbo = tk.Entry(frame_frances, textvariable=palabra)
    entrada_verbo.pack(side="left", pady=20, padx=30)
    entrada_verbo.focus()
    entrada_verbo.config(font=("Corbel", 15))

    boton_frances_inf = tk.Button(frame_frances, text="Infinitivo", command=verboinf)
    boton_frances_inf.pack(side="left", pady=20, padx=10, expand=True)
    boton_frances_inf.config(font=("Corbel", 15))


def comando_aleman():
    frame.destroy()

    def comando_aleman_infinitivo():
        try:
            framefinal = tk.Frame(root, background="white")
            framefinal.pack()

            buscar_aleman_inf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_inf[0], 1]
            traduccion = traduccion_aleman[0]

            label_verbo = tk.Label(framefinal, text="Verbo en infinitivo:")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            label_verbofinal = tk.Label(framefinal, text=traduccion)
            label_verbofinal.pack(side="top")
            label_verbofinal.config(font=("Corbel", 15))

        except:
            label_verbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            print("Verbo no encontrado")

    def comando_aleman_preterito():
        try:
            framefinal = tk.Frame(root, background="white")
            framefinal.pack()

            buscar_aleman_pre = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pre[0], 2]
            traduccion = traduccion_aleman[0]

            label_verbo = tk.Label(framefinal, text="Verbo en pretérito:")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            label_verbofinal = tk.Label(framefinal, text=traduccion)
            label_verbofinal.pack(side="top")
            label_verbofinal.config(font=("Corbel", 15))

        except:
            label_verbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            print("Verbo no encontrado")


    def comando_aleman_pasperf():
        try:
            framefinal = tk.Frame(root, background="white")
            framefinal.pack()

            buscar_aleman_pasperf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pasperf[0], 3]
            traduccion = traduccion_aleman[0]

            label_verbo = tk.Label(framefinal, text="Verbo en pasado perfecto:")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            label_verbofinal = tk.Label(framefinal, text=traduccion)
            label_verbofinal.pack(side="top")
            label_verbofinal.config(font=("Corbel", 15))

        except:
            label_verbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            print("Verbo no encontrado")



    def comando_aleman_todos():
        try:
            framefinal = tk.Frame(root, background="white")
            framefinal.pack()

            buscar_aleman_inf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_inf[0], 1]
            traduccioninf = traduccion_aleman[0]

            label_verbo_inf = tk.Label(framefinal, text="Verbo en infinitivo:")
            label_verbo_inf.pack(side="top")
            label_verbo_inf.config(font=("Corbel", 15))

            label_verbofinal_inf = tk.Label(framefinal, text=traduccioninf)
            label_verbofinal_inf.pack(side="top")
            label_verbofinal_inf.config(font=("Corbel", 15))

            buscar_aleman_pre = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pre[0], 2]
            traduccionpre = traduccion_aleman[0]

            label_verbo_pre = tk.Label(framefinal, text="Verbo en pretérito:")
            label_verbo_pre.pack(side="top")
            label_verbo_pre.config(font=("Corbel", 15))

            label_verbofinal_pre = tk.Label(framefinal, text=traduccionpre)
            label_verbofinal_pre.pack(side="top")
            label_verbofinal_pre.config(font=("Corbel", 15))

            buscar_aleman_pasperf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pasperf[0], 3]
            traduccionpasperf = traduccion_aleman[0]

            label_verbo_perf = tk.Label(framefinal, text="Verbo en pasado perfecto:")
            label_verbo_perf.pack(side="top")
            label_verbo_perf.config(font=("Corbel", 15))

            label_verbofinal_perf = tk.Label(framefinal, text=traduccionpasperf)
            label_verbofinal_perf.pack(side="top")
            label_verbofinal_perf.config(font=("Corbel", 15))
        except:
            label_verbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_verbo.pack(side="top")
            label_verbo.config(font=("Corbel", 15))

            print("Verbo no encontrado")


    frame_aleman = tk.Frame(root, background="white")
    frame_aleman.pack()

    label_aleman = tk.Label(frame_aleman, text="Verbo:")
    label_aleman.pack(side="top")
    label_aleman.config(font=("Corbel", 15))

    entrada_verbo = tk.Entry(frame_aleman, textvariable=palabra)
    entrada_verbo.pack(side="top", pady=20, padx=30)
    entrada_verbo.focus()
    entrada_verbo.config(font=("Corbel", 15))

    label_aleman2 = tk.Label(frame_aleman, text="Tiempo:")
    label_aleman2.pack(side="top")
    label_aleman2.config(font=("Corbel", 15))

    boton_aleman_infinitivo = tk.Button(frame_aleman, text="Infinitivo", command=comando_aleman_infinitivo)
    boton_aleman_infinitivo.pack(side="left", pady=20, padx=10, expand=True)
    boton_aleman_infinitivo.config(font=("Corbel", 15))

    boton_aleman_preterito = tk.Button(frame_aleman, text="Pretérito", command=comando_aleman_preterito)
    boton_aleman_preterito.pack(side="left", pady=20, padx=10, expand=True)
    boton_aleman_preterito.config(font=("Corbel", 15))

    boton_aleman_pasadoperf = tk.Button(frame_aleman, text="Pasado", command=comando_aleman_pasperf)
    boton_aleman_pasadoperf.pack(side="left", pady=20, padx=10, expand=True)
    boton_aleman_pasadoperf.config(font=("Corbel", 15))

    boton_aleman_todos = tk.Button(frame_aleman, text="Todos", command=comando_aleman_todos)
    boton_aleman_todos.pack(side="left", pady=20, padx=10, expand=True)
    boton_aleman_todos.config(font=("Corbel", 15))


frame = tk.Frame(root, background="white")
frame.pack()

label = tk.Label(frame, text="¿A qué idioma deseas traducir tu verbo?", background="grey")
label.pack(side="top")
label.config(font=("sweet purple", 40))

boton_frances = tk.Button(frame, text="Francés", command=comando_frances)
boton_frances.pack(side="left", pady=20, padx=50, expand=True)
boton_frances.config(font=("Corbel", 15))

boton_aleman = tk.Button(frame, text="Alemán", command=comando_aleman)
boton_aleman.pack(side="left", pady=20, padx=50, expand=True)
boton_aleman.config(font=("Corbel", 15))

boton_adios = tk.Button(frame, text="Cancelar", command=root.destroy)
boton_adios.pack(side="right", pady=20, padx=50, expand=True)
boton_adios.config(font=("Corbel", 15))

root.mainloop()
