import requests
import pandas as pd


# Funcao retorna todos os dados com formatacao de csv
def getDados(coluna):

    # Realiza requisicao dos dados na web
    print("Requisitando dados em: https://trab-lingprog-default-rtdb.firebaseio.com/Dados.json ...")
    reqResult = requests.get('https://trab-lingprog-default-rtdb.firebaseio.com/Dados.json')

    # Checa se a requisicao foi completada com sucesso (status code 200).
    # Caso contrario, o programa sai com codigo de erro '1'
    if (reqResult.status_code != 200):
        print("Erro de requisicao.")
        exit(1)
    else:
        print("Requisicao realizada com sucesso.")

    print(coluna)
    
    data = pd.read_json(reqResult.text)

    print(data.to_csv())

    toCpp = data.to_csv()

    return str(toCpp)


# Funcao recebe o nome de uma coluna da base e retorna os 
# valores contidos nesta.
def getDadosColuna(coluna):

    # Realiza requisicao dos dados na web
    reqResult = requests.get('https://trab-lingprog-default-rtdb.firebaseio.com/Dados.json')

    # Checa se a requisicao foi completada com sucesso (status code 200).
    # Caso contrario, o programa sai com codigo de erro '1'
    if (reqResult.status_code != 200):
        print("Erro de requisicao.")
        exit(1)
    else:
        print("Requisicao realizada com sucesso.")

    print(coluna)
    data = pd.read_json(reqResult.text)

    # Filtra os dados pela coluna desejada
    filtered = data[coluna]

    print(filtered)

    toCpp = filtered.values

    if (coluna == "porta"):
        
        print(toCpp)

        result = str(toCpp)[1:-1].replace("  ", ",")
        result = result.replace(" ", "")
  
    else:
        result = str(toCpp)[1:-1].replace(" ", ",")

    return result


# Utilizado em teste02.cpp
# getDadosColuna("COLUNA")
