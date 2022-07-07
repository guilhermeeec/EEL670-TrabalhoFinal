#include "dumbApiDebug.h"

string dadosTemperatura(DADOS_TEMPERATURA_EXEMPLO);
string dadosPorta(DADOS_PORTA_EXEMPLO);

string queryDadosTemperatura() {
    return dadosTemperatura;
}

string queryDadosPorta() {
    return dadosPorta;
}

int insertDadosPorta(string dadoNovo) {
    dadosPorta.append(dadoNovo);
    return 0;
}