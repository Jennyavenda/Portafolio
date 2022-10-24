import requests
from bs4 import BeautifulSoup
import numpy as np
import tkinter as tk

#####################################ALEMAN#####################################

urlaleman = 'https://www.gramatica-alemana.es/gramatica/verbos-irregulares'
responsealeman = requests.get(urlaleman)

soupaleman = BeautifulSoup(responsealeman.text, 'html.parser')
aleman_table = soupaleman.find('table', {'class': 'gentable'}).find('tbody')
alemantable_rows = aleman_table.find_all('tr')
alemanmatrix_results = []

for i, row in enumerate(alemantable_rows):
    if(i < len(alemantable_rows)):
        inner_matrix = []
        data_tds = row.find_all('td')
        if data_tds != []:
            verbs = row.find('td')
            if verbs is not None:
                verbs_string = verbs.getText().rstrip("\t").rstrip("\n")
                for j, column in enumerate(data_tds):
                    verbs2_string = column.getText().rstrip("\t").rstrip("\n")
                    inner_matrix.append(verbs2_string)
                    if row is None:
                        verbs2_string = ""
                    if column is None:
                        verbs_string = " "
                alemanmatrix_results.append(inner_matrix)

csv_data_aleman = np.array(alemanmatrix_results)
np.savetxt('verbosalemán.csv', csv_data_aleman, delimiter=',', fmt='%s')


#####################################FRÁNCES#####################################

urlfrances = 'https://elblogdeidiomas.es/100-verbos-frances-traduccion/'
responsefrances = requests.get(urlfrances)

soupfrances = BeautifulSoup(responsefrances.text, 'html.parser')
frances_table = soupfrances.find('div', {'class': 'entry-inner'})
francestable_rows = frances_table.find_all('ol')
francesmatrix_results = []

for i, row in enumerate(francestable_rows):
    if(i < len(francestable_rows)):
        data_tds = row.find_all('li')
        if data_tds != []:
            verbs = row.find('li')
            if verbs is not None:
                verbs_string = verbs.getText().rstrip("\n").replace(',', '/')
                for j, column in enumerate(data_tds):
                    verbs2_string = column.getText().rstrip("\n").replace(',', '/')
                    verbs2_string2 = verbs2_string.split(": ")
                    francesmatrix_results.append(verbs2_string2)  
                if row is None:
                    verbs_string = ""
            if column is None:
                verbs2_string = " "
                francesmatrix_results.append(francesmatrix_results)

csv_data_frances = np.array(francesmatrix_results)
np.savetxt('verbosfrancés.csv', francesmatrix_results, delimiter=',', fmt='%s')

###########################################################################################################################################

root = tk.Tk()
root.title("Verbooos")
root.config(background="grey")
palabra = tk.StringVar()
#palabra = "beber"


def comando_frances():
    frame.destroy()

    def verboinf():
        try: 
            framefinal = tk.Frame(root, background="light grey")
            framefinal.pack()

            buscar_frances = np.where(csv_data_frances == palabra.get())
            traduccion_frances = csv_data_frances[buscar_frances[0], 0]
            traduccion = traduccion_frances[0]
            print(traduccion)

            label_francesverbo = tk.Label(framefinal, text="Verbo en francés:")
            label_francesverbo.pack(side="top")

            label_francesverbofinal = tk.Label(framefinal, text=traduccion)
            label_francesverbofinal.pack(side="top")

        except:
            label_francesverbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_francesverbo.pack(side="top")

            print("Verbo no encontrado")

    frame_frances = tk.Frame(root, background="light grey")
    frame_frances.pack()

    label_frances = tk.Label(frame_frances, text="Verbo:")
    label_frances.pack(side="top")

    entrada_verbo = tk.Entry(frame_frances, textvariable=palabra)
    entrada_verbo.pack(side="left", pady=20, padx=30)
    entrada_verbo.focus()

    boton_frances_inf = tk.Button(frame_frances, text="Infinitivo", command=verboinf)
    boton_frances_inf.pack(side="left", pady=20, padx=10, expand=True)


def comando_aleman():
    frame.destroy()

    def comando_aleman_infinitivo():
        try:
            framefinal = tk.Frame(root, background="light grey")
            framefinal.pack()

            buscar_aleman_inf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_inf[0], 1]
            traduccion = traduccion_aleman[0]

            label_francesverbo = tk.Label(framefinal, text="Verbo en infinitivo:")
            label_francesverbo.pack(side="top")

            label_francesverbofinal = tk.Label(framefinal, text=traduccion)
            label_francesverbofinal.pack(side="top")

        except:
            label_francesverbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_francesverbo.pack(side="top")

            print("Verbo no encontrado")

    def comando_aleman_preterito():
        try:
            framefinal = tk.Frame(root, background="light grey")
            framefinal.pack()

            buscar_aleman_pre = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pre[0], 2]
            traduccion = traduccion_aleman[0]

            label_francesverbo = tk.Label(framefinal, text="Verbo en pretérito:")
            label_francesverbo.pack(side="top")

            label_francesverbofinal = tk.Label(framefinal, text=traduccion)
            label_francesverbofinal.pack(side="top")

        except:
            label_francesverbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_francesverbo.pack(side="top")

            print("Verbo no encontrado")


    def comando_aleman_pasperf():
        try:
            framefinal = tk.Frame(root, background="light grey")
            framefinal.pack()

            buscar_aleman_pasperf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pasperf[0], 3]
            traduccion = traduccion_aleman[0]

            label_francesverbo = tk.Label(framefinal, text="Verbo en pasado perfecto:")
            label_francesverbo.pack(side="top")

            label_francesverbofinal = tk.Label(framefinal, text=traduccion)
            label_francesverbofinal.pack(side="top")

        except:
            label_francesverbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_francesverbo.pack(side="top")

            print("Verbo no encontrado")



    def comando_aleman_todos():
        try:
            framefinal = tk.Frame(root, background="light grey")
            framefinal.pack()

            buscar_aleman_inf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_inf[0], 1]
            traduccioninf = traduccion_aleman[0]

            label_francesverbo_inf = tk.Label(framefinal, text="Verbo en infinitivo:")
            label_francesverbo_inf.pack(side="top")

            label_francesverbofinal_inf = tk.Label(framefinal, text=traduccioninf)
            label_francesverbofinal_inf.pack(side="top")

            buscar_aleman_pre = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pre[0], 2]
            traduccionpre = traduccion_aleman[0]

            label_francesverbo_pre = tk.Label(framefinal, text="Verbo en pretérito:")
            label_francesverbo_pre.pack(side="top")

            label_francesverbofinal_pre = tk.Label(framefinal, text=traduccionpre)
            label_francesverbofinal_pre.pack(side="top")

            buscar_aleman_pasperf = np.where(csv_data_aleman == palabra.get())
            traduccion_aleman = csv_data_aleman[buscar_aleman_pasperf[0], 3]
            traduccionpasperf = traduccion_aleman[0]

            label_francesverbo_perf = tk.Label(framefinal, text="Verbo en pasado perfecto:")
            label_francesverbo_perf.pack(side="top")

            label_francesverbofinal_perf = tk.Label(framefinal, text=traduccionpasperf)
            label_francesverbofinal_perf.pack(side="top")
        except:
            label_francesverbo = tk.Label(framefinal, text="Verbo no encontrado")
            label_francesverbo.pack(side="top")

            print("Verbo no encontrado")


    frame_aleman = tk.Frame(root, background="light grey")
    frame_aleman.pack()

    label_aleman = tk.Label(frame_aleman, text="Verbo:")
    label_aleman.pack(side="top")

    entrada_verbo = tk.Entry(frame_aleman, textvariable=palabra)
    entrada_verbo.pack(side="top", pady=20, padx=30)
    entrada_verbo.focus()

    label_aleman2 = tk.Label(frame_aleman, text="Tiempo:")
    label_aleman2.pack(side="top")

    boton_aleman_infinitivo = tk.Button(frame_aleman, text="Infinitivo", command=comando_aleman_infinitivo)
    boton_aleman_infinitivo.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_preterito = tk.Button(frame_aleman, text="Pretérito", command=comando_aleman_preterito)
    boton_aleman_preterito.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_pasadoperf = tk.Button(frame_aleman, text="Pasado", command=comando_aleman_pasperf)
    boton_aleman_pasadoperf.pack(side="left", pady=20, padx=10, expand=True)

    boton_aleman_todos = tk.Button(frame_aleman, text="Todos", command=comando_aleman_todos)
    boton_aleman_todos.pack(side="left", pady=20, padx=10, expand=True)


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


root.mainloop()
