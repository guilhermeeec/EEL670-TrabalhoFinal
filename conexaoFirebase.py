import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
import requests
import pandas as pd


def getDadosTemp(coluna):

    # Acessa a nsosa plataforma do Firebase em nuvem
    req = requests.get("https://trab-lingprog-default-rtdb.firebaseio.com/Temperatura.json")
    if (req.status_code != 200):
        print("Erro de requisicao.")
        exit(1)
    else:
        print("Requisicao realizada com sucesso.")

    # Pega a resposta no formato JSON e cria tabela do pacote pandas
    data = pd.read_json(req.text)
    data["id"] = data.index

    # Coleta as informacoes dos dados
    id = data["id"]
    timestamp = data["timestamp"].values
    temp = data["temperatura"].values

    # Itera sobre tabela
    result = ""
    for index in range(len(data)):
    
        # Monta string referente a um dado
        strParcial = str(id[index])+","+ str(timestamp[index])+","+ str(temp[index])
        
        # Insere dado no resultado
        if (index==0):
            result = strParcial
        else:
            result += ";" + strParcial

    return result

def getDadosPorta(coluna):

    # Acessa a nsosa plataforma do Firebase em nuvem
    req= requests.get("https://trab-lingprog-default-rtdb.firebaseio.com/StatusPorta.json")
    if (req.status_code != 200):
        print("Erro de requisicao.")
        exit(1)
    else:
        pass
        #print("Requisicao realizada com sucesso.")

    # Pega a resposta no formato JSON e cria tabela do pacote pandas
    data = pd.read_json(req.text)
    data["id"] = data.index

    # Coleta as informacoes dos dados
    id = data["id"]
    timestamp = data["timestamp"].values
    porta = data["aberta"].values

    # Itera sobre tabela   
    result = ""
    for index in range(len(data)):
    
        # Monta string referente a um dado
        strParcial = str(id[index])+","+ str(timestamp[index])+","+ str(porta[index])
        
        # Insere dado no resultado
        if (index==0):
            result = strParcial
        else:
            result += ";" + strParcial

    return result

def insertDadosTemp(registro):

        # Credencial gerada em 'Configuracoes do projeto -> Contas de Servico -> Gerar nova chave privada'
        cred = credentials.Certificate("./credentials/trab-lingprog-firebase-adminsdk-nhkuh-3b53b7a136.json")
        
        default_app = firebase_admin.initialize_app(cred, {
                'databaseURL':'https://trab-lingprog-default-rtdb.firebaseio.com/'
                })

        # Pensar em forma mais inteligente de organizar o DB
        # /Dados/2 -> o 2 corresponde  
        ref = db.reference("/Temperatura/")
        listaRegs = registro.split(";")
        matrizRegs = []

        for reg in listaRegs:
                matrizRegs.append(reg.split(","))

        for reg in matrizRegs:
        
                # /Temperatura/<chave primaria 0, 1, 2>/<timestamp, temperatura>
                ref.child(reg[0]).child("timestamp").set(int(reg[1]))
                ref.child(reg[0]).child("temperatura").set(float(reg[2]))       
        
        return 0

def insertDadosPorta(registro):
        # Credencial gerada em 'Configuracoes do projeto -> Contas de Servico -> Gerar nova chave privada'
        cred = credentials.Certificate("./credentials/trab-lingprog-firebase-adminsdk-nhkuh-3b53b7a136.json")

        default_app = firebase_admin.initialize_app(cred, {
                'databaseURL':'https://trab-lingprog-default-rtdb.firebaseio.com/'
                })

        # Pensar em forma mais inteligente de organizar o DB
        # /Dados/2 -> o 2 corresponde  
        ref = db.reference("/StatusPorta/")
        listaRegs = registro.split(";")
        matrizRegs = []

        for reg in listaRegs:
                matrizRegs.append(reg.split(","))

        for reg in matrizRegs:
               
                # /StatusPorta/<chave primaria 0, 1, 2>/<timestamp, aberta>
                ref.child(reg[0]).child("timestamp").set(int(reg[1]))
                ref.child(reg[0]).child("aberta").set(True if  reg[2].lower() == "true" else False)     
        
        return 0

# Teste 
if __name__ == "__main__":
    getDadosTemp("")
    getDadosPorta("")
    insertDadosPorta("0,1800,True")
