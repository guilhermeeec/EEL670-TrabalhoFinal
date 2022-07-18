import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# Credencial gerada em 'Configuracoes do projeto -> Contas de Servico -> Gerar nova chave privada'
cred = credentials.Certificate("./credentials/trab-lingprog-firebase-adminsdk-nhkuh-3b53b7a136.json")

default_app = firebase_admin.initialize_app(cred, {
	'databaseURL':'https://trab-lingprog-default-rtdb.firebaseio.com/'
	})

# Pensar em forma mais inteligente de organizar o DB
# /Dados/2 -> o 2 corresponde  
ref = db.reference("/Dados/")

# Dados a serem inseridos na base. 
data = {'2':{'hora':14 , 'porta':False , 'temp': 18},
        '3':{'hora':15 , 'porta':False , 'temp': 15}}

# Itera por todas as keys, acessando os valores do dicionario referentes a ela.
for key, values in data.items():
    for attrName, attrValue in values.items():
        
        print(key)
        print(attrName)
        print(attrValue)
        
        # /Dados/<chave primaria 0, 1, 2>/<hora, porta, temp>/<valor a ser inserido no campo>
        ref.child(key).child(attrName).set(attrValue)

print(ref.get())


