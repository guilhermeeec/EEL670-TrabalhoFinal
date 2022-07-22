#include "dumbApiDebug.h"
#include "iostream"

string dadosTemperatura(DADOS_TEMPERATURA_EXEMPLO);
string dadosPorta(DADOS_PORTA_EXEMPLO);

string queryDadosTemperatura() {
    cout << "Usando dados fake de temp..." << endl;
    return dadosTemperatura;
}

string queryDadosPorta() {
    cout << "Usando dados fake de porta..." << endl;
    return dadosPorta;
}

int insertDadosPorta(string dadoNovo) {
    dadosPorta.append(dadoNovo);
    return 0;
}