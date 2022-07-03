#include "datasetTemperatura.h"
#include "dumbApiDebug.h"
#include <iomanip>

#define ZERO_ABSOLUTO   -273 
#define INFINITO        10000 

DatasetTemperatura::DatasetTemperatura() :
Dataset(), vetorTemperaturas(0) { consultarDados(); }

void DatasetTemperatura::consultarDados() {

    // dadosRetornados: "0,10,29;1,13,32;2,16,21;3,18,27"
    string dadosRetornados = queryDadosTemperatura();

    // dados: ["0,10,29" "1,13,32" "2,16,21" "3,18,27"]
    vector<string> dados = fatiarString(dadosRetornados, ";");

    for(string dado : dados) {

        // campos: ["0" "10" "29"]
        vector<string> campos = fatiarString(dado, ",");

        unsigned id = (unsigned)stoul(campos[0],nullptr);
        unsigned hora = (unsigned)stoul(campos[1],nullptr);
        float medida = (float)stof(campos[2],nullptr);

        temperatura_t amostra;
        amostra.id = id;
        amostra.hora = hora;
        amostra.medida = medida;

        vetorTemperaturas.push_back(amostra);
    }
}

void DatasetTemperatura::exibirDados() {
    cout << left << setw(9) << "ID" 
         << left << setw(9) << "Horario" 
         << left << setw(9) << "Valor (graus C)" << endl;
    for (temperatura_t amostra : vetorTemperaturas) 
        cout << left << setw(9) << amostra.id 
             << left << setw(9) << amostra.hora 
             << left << setw(9) << amostra.medida << endl;
}

void DatasetTemperatura::exibirEstatisticas() {
    float media = this->calcularMedia();
    float maximo, minimo;
    this->calcularMaxMin(maximo, minimo);
    unsigned intervalo = calcularIntervalo();

    cout << left << setw(15) << "Estatistica" << "Valor" << endl;
    cout << left << setw(15) << "Media" << media << endl;
    cout << left << setw(15) << "Maximo" << maximo << endl;
    cout << left << setw(15) << "Minimo" << minimo << endl;
    cout << left << setw(15) << "Intervalo" << intervalo << endl;
} 

float DatasetTemperatura::calcularMedia() {
    float soma = 0;;
    float media = 0;
    for(temperatura_t amostra : vetorTemperaturas)
        soma += amostra.medida;

    try {
        if (vetorTemperaturas.size() == 0)
            throw ExcecaoDivisaoPorZero();
        else
            media = soma/vetorTemperaturas.size();
    }
    catch (ExcecaoDivisaoPorZero& excecao) {
        cerr << excecao.what() << "Nenhum dado coletado (media incorreta)" << endl;
    }

    return media;
}

void DatasetTemperatura::calcularMaxMin(float& ref_maximo, float& ref_minimo) {
    ref_maximo = ZERO_ABSOLUTO;
    ref_minimo = INFINITO;

    for(temperatura_t amostra : vetorTemperaturas) {
        if(amostra.medida > ref_maximo)
            ref_maximo = amostra.medida;
        if(amostra.medida < ref_minimo)
            ref_minimo = amostra.medida;
    }
}

unsigned DatasetTemperatura::calcularIntervalo() {
    vector<temperatura_t>::iterator it_inicio = vetorTemperaturas.begin();
    temperatura_t primeiraAmostra = *it_inicio;
    unsigned tempoInicial = primeiraAmostra.hora;

    vector<temperatura_t>::iterator it_fim = vetorTemperaturas.end()-1;
    temperatura_t ultimaAmostra = *it_fim;
    unsigned tempoFinal = ultimaAmostra.hora;

    unsigned deltaT;
    try {
        deltaT = tempoFinal - tempoInicial;
        if(deltaT < 0) throw ExcecaoHorarioInconsistente();
    }
    catch (ExcecaoHorarioInconsistente& excecao) {
        cerr << excecao.what() << "Alerta para problemas no sincronismo do BD (intervalo estranho)" << endl;
    }

    return deltaT;
}