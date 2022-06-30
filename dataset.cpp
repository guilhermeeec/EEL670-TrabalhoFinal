#include "dataset.h"

Dataset::Dataset() : vetorDados(0) {}

void Dataset::consultarDados() {};
void Dataset::exibirDados() {};
void Dataset::exibirEstatisticas() {};

ostream& operator<<(ostream& out, Dataset* dados) {
    dados->exibirDados();
    return out;
}

vector<string> fatiarString(string texto, string delimitador) {
    vector<string> fatias;
    size_t posicao = 0;
    string token;
    while((posicao = texto.find(delimitador)) != string::npos) {
        token = texto.substr(0, posicao);
        fatias.push_back(token);
        texto.erase(0, posicao+delimitador.length());
    }
    fatias.push_back(texto);
    return fatias;
}
