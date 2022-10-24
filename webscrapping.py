import requests
from bs4 import BeautifulSoup

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
