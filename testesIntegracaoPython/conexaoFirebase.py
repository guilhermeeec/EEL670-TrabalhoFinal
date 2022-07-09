import requests
import pandas as pd

# Realiza requisicao dos dados na web
reqResult = requests.get('https://trab-lingprog-default-rtdb.firebaseio.com/Dados.json')

# Checa se a requisicao foi completada com sucesso (status code 200).
# Caso contrario, o programa sai com codigo de erro '1'
if (reqResult.status_code != 200):
    print("Erro de requisicao.")
    exit(1)
else:
    print("Requisicao realizada com sucesso.")


data = pd.read_json(reqResult.text)

print(data)