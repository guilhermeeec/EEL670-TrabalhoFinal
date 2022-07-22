#include "datasetTemperatura.h"
#include "excecoes.h"
#include "dumbApiDebug.h"
#include "chamadasPython.h"
#include <iomanip>

#define ZERO_ABSOLUTO   -273 
#define INFINITO        10000 

DatasetTemperatura::DatasetTemperatura() :
Dataset(), vetorTemperaturas(0) { consultarDados(); }

void DatasetTemperatura::consultarDados() {

    // dadosRetornados: "0,36000,29;1,46015,32;2,57900,21;3,67523,27"
    string dadosRetornados = queryDadosTemperatura();

    // dados: ["0,36000,29" "1,46015,32" "2,57900,21" "3,67523,27"]
    vector<string> dados = fatiarString(dadosRetornados, ";");

    for(string dado : dados) {

        // campos: ["0" "36000" "29"]
        vector<string> campos = fatiarString(dado, ",");

        unsigned id = (unsigned)stoul(campos[0],nullptr);
        unsigned timestamp = (unsigned)stoul(campos[1],nullptr);
        float medida = (float)stof(campos[2],nullptr);

        horario_t horario(timestamp);

        temperatura_t amostra;
        amostra.id = id;
        amostra.hora = horario;
        amostra.medida = medida;

        vetorTemperaturas.push_back(amostra);
    }
}

void DatasetTemperatura::exibirDados() {
    cout << left << setw(9) << "ID" 
         << left << setw(15) << "Horario" 
         << left << setw(15) << "Valor (graus C)" << endl;
    for (temperatura_t amostra : vetorTemperaturas) 
        cout << left << setw(9) << amostra.id 
             << left << setw(15) << amostra.hora 
             << left << setw(15) << amostra.medida << endl;
}

void DatasetTemperatura::exibirEstatisticas() {
    float media = this->calcularMedia();
    float maximo, minimo;
    this->calcularMaxMin(maximo, minimo);
    horario_t intervalo = calcularIntervalo();

    cout << left << setw(25) << "Estatistica" << "Valor" << endl;
    cout << left << setw(25) << "Media" << media << endl;
    cout << left << setw(25) << "Maximo" << maximo << endl;
    cout << left << setw(25) << "Minimo" << minimo << endl;
    cout << left << setw(25) << "Intervalo" << intervalo << endl;
} 

float DatasetTemperatura::calcularMedia() {
    float soma = vetorTemperaturas[0].medida;
    float media = 0;
    if(vetorTemperaturas.size() == 1)
        return soma;

    // Calcula a media da variavel implementando uma integracao por trapezios
    for(unsigned indice=1; indice<vetorTemperaturas.size(); indice++){
        temperatura_t temperaturaAtual = vetorTemperaturas[indice];
        temperatura_t temperaturaAnterior = vetorTemperaturas[indice-1];
        horario_t diferenca = temperaturaAtual.hora - temperaturaAnterior.hora;
        unsigned deltaT = diferenca.horarioToTimestamp();
        soma += deltaT * (temperaturaAtual.medida + temperaturaAtual.medida) / 2;
    }

    unsigned diferencaTotal = calcularIntervalo().horarioToTimestamp();

    try {
        if (vetorTemperaturas.size() == 0)
            throw ExcecaoDivisaoPorZero();
        else
            media = soma/diferencaTotal;
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

horario_t DatasetTemperatura::calcularIntervalo() {
    vector<temperatura_t>::iterator it_inicio = vetorTemperaturas.begin();
    temperatura_t primeiraAmostra = *it_inicio;
    horario_t tempoInicial = primeiraAmostra.hora;

    vector<temperatura_t>::iterator it_fim = vetorTemperaturas.end()-1;
    temperatura_t ultimaAmostra = *it_fim;
    horario_t tempoFinal = ultimaAmostra.hora;

    horario_t deltaT;
    try {
        deltaT = tempoFinal - tempoInicial;
    }
    catch (ExcecaoHorarioInconsistente& excecao) {
        cerr << excecao.what() << "Alerta para problemas no sincronismo do BD (intervalo estranho)" << endl;
    }

    return deltaT;
} 