#include "datasetPorta.h"
#include "excecoes.h"
#include "dumbApiDebug.h"
#include <iomanip>

DatasetPorta::DatasetPorta() :
Dataset(), vetorDados(0) { consultarDados(); }

void DatasetPorta::consultarDados() {

    // dadosRetornados: "0,10,True;1,13,False;2,16,False;3,18,True"
    string dadosRetornados = queryDadosPorta();

    // dados: ["0,10,True" "1,13,False" "2,16,False" "3,18,True"]
    vector<string> dados = fatiarString(dadosRetornados, ";");

    for(string dado : dados) {

        // campos: ["0" "10" "True"]
        vector<string> campos = fatiarString(dado, ",");

        unsigned id = (unsigned)stoul(campos[0],nullptr);
        unsigned hora = (unsigned)stoul(campos[1],nullptr);
        bool aberta = (campos[2] == "True" ? true : false);

        porta_t amostra;
        amostra.id = id;
        amostra.hora = hora;
        amostra.aberta = aberta;

        vetorDados.push_back(amostra);
    }
}

void DatasetPorta::exibirDados() {
    cout << left << setw(9) << "ID" 
         << left << setw(9) << "Horario" 
         << left << setw(9) << "Estado" << endl;
    for (porta_t amostra : vetorDados) {
        string textoEstado =  (amostra.aberta ? "Aberta" : "Fechada");
        cout << left << setw(9) << amostra.id 
             << left << setw(9) << amostra.hora 
             << left << setw(9) << textoEstado << endl;
    }
}

void DatasetPorta::exibirEstatisticas() {
    unsigned tempoAberta = this->calcularTempoAberta();
    unsigned intervalo = calcularIntervalo();
    unsigned tempoFechada = intervalo - tempoAberta;

    cout << left << setw(25) << "Estatistica" << "Valor" << endl;
    cout << left << setw(25) << "Tempo aberta" << tempoAberta << endl;
    cout << left << setw(25) << "Tempo fechada" << tempoFechada << endl;
    cout << left << setw(25) << "Intervalo" << intervalo << endl;
} 

unsigned DatasetPorta::calcularTempoAberta() {
}

unsigned DatasetPorta::calcularIntervalo() {
    vector<porta_t>::iterator it_inicio = vetorDados.begin();
    porta_t primeiraAmostra = *it_inicio;
    unsigned tempoInicial = primeiraAmostra.hora;

    vector<porta_t>::iterator it_fim = vetorDados.end()-1;
    porta_t ultimaAmostra = *it_fim;
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