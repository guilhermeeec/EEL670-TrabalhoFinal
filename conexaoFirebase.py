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

    #print(coluna)
    
    data = pd.read_json(reqResult.text)

    #print(data.to_csv())

    toCpp = data.to_csv()

    return str(toCpp)

def getDadosTemp(coluna):

    req= requests.get("https://trab-lingprog-default-rtdb.firebaseio.com/Temperatura.json")

    if (req.status_code != 200):
        print("Erro de requisicao.")
        exit(1)
    else:
        print("Requisicao realizada com sucesso.")

    data = pd.read_json(req.text)
    data["id"] = data.index

    id = data["id"]
    timestamp = data["timestamp"].values
    temp = data["temperatura"].values

    print(timestamp)
    print(temp)

    result = ""

    for index in range(len(data)):
    
        strParcial = str(id[index])+","+ str(timestamp[index])+","+ str(temp[index])
        
        if (index==0):
            result = strParcial
        else:
        
            resultTemp = result
            strParcial = str(id[index])+","+ str(timestamp[index])+","+ str(temp[index])
            result = resultTemp + ";" + strParcial

    print(result)

    return result

def getDadosPorta(coluna):

    req= requests.get("https://trab-lingprog-default-rtdb.firebaseio.com/StatusPorta.json")

    if (req.status_code != 200):
        print("Erro de requisicao.")
        exit(1)
    else:
        print("Requisicao realizada com sucesso.")

    data = pd.read_json(req.text)
    data["id"] = data.index

    id = data["id"]
    timestamp = data["timestamp"].values
    porta = data["aberta"].values

    print(timestamp)
    print(porta)

    result = ""

    for index in range(len(data)):
    
        strParcial = str(id[index])+","+ str(timestamp[index])+","+ str(porta[index])
        
        if (index==0):
            result = strParcial
        else:
        
            resultTemp = result
            strParcial = str(id[index])+","+ str(timestamp[index])+","+ str(porta[index])
            result = resultTemp + ";" + strParcial

    print(result)
    
    return result

if __name__ == "__main__":
    getDadosTemp("")
    getDadosPorta("")






# # Funcao recebe o nome de uma coluna da base e retorna os 
# # valores contidos nesta.
# def getDadosColuna(coluna):

#     # Realiza requisicao dos dados na web
#     reqResult = requests.get('https://trab-lingprog-default-rtdb.firebaseio.com/Dados.json')

#     # Checa se a requisicao foi completada com sucesso (status code 200).
#     # Caso contrario, o programa sai com codigo de erro '1'
#     if (reqResult.status_code != 200):
#         print("Erro de requisicao.")
#         exit(1)
#     else:
#         print("Requisicao realizada com sucesso.")

#     data = pd.read_json(reqResult.text)
#     data["id"] = data.index

#     id = data["id"].values
#     hora = data["hora"].values
#     colunaDados = data[coluna].values

#     result = "" 
#     for index in range(len(data)):
        
#         strParcial = str(id[index])+","+ str(hora[index])+","+ str(colunaDados[index])
       
#         if (index==0):
#             result = strParcial
#         else:
        
#             resultTemp = result
#             strParcial = str(id[index])+","+ str(hora[index])+","+ str(colunaDados[index])
#             result = resultTemp + ";" + strParcial

#     return result


# Utilizado em teste02.cpp
# getDadosColuna("COLUNA")