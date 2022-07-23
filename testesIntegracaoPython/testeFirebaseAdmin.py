import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# Formato insercao <index>,<timestamp>,<valor>;<index2>,<timestamp2>,<valor2>;


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

        #print(matrizRegs)


        for reg in matrizRegs:
               
                # /StatusPorta/<chave primaria 0, 1, 2>/<timestamp, aberta>
                ref.child(reg[0]).child("timestamp").set(int(reg[1]))
                ref.child(reg[0]).child("aberta").set(bool(reg[2]))       
        
        return 0

registroTestePorta = "4,36000,True;5,46015,False;6,57900,False;7,67523,True"

#insertRegistroPorta(registroTestePorta)


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

        #print(matrizRegs)


        for reg in matrizRegs:
               
                # /Temperatura/<chave primaria 0, 1, 2>/<timestamp, temperatura>
                ref.child(reg[0]).child("timestamp").set(int(reg[1]))
                ref.child(reg[0]).child("temperatura").set(float(reg[2]))       
        
        return 0

resgistroTesteTemp =  "0,36000,29;1,46015,32;2,57900,21;3,67523,27"
resgistroTesteTemp2 = "4,72000,22.5"

insertDadosTemp(resgistroTesteTemp)
