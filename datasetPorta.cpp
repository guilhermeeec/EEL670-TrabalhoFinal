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

void DatasetPorta::publicarDados(string dado) {
    insertDadosPorta(dado);
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

void DatasetPorta::abrirFecharPorta() {
    bool abertaNoMomento = (vetorDados.end()-1)->aberta;
    unsigned ultimoId = (vetorDados.end()-1)->id;

    porta_t novoDado;
    novoDado.hora = 10;
    novoDado.id = ultimoId+1;
    if(abertaNoMomento) {
        novoDado.aberta = false;
        cout << "Porta fechada" << endl;
    } else {
        novoDado.aberta = true;
        cout << "Porta aberta" << endl;
    }
    vetorDados.push_back(novoDado);

    string idString(to_string(novoDado.id));
    string horaString(to_string(novoDado.hora));
    string boolString = novoDado.aberta ? "True" : "False";
    string dado(idString + "," + horaString + "," + boolString);

    publicarDados(dado);
}

unsigned DatasetPorta::calcularTempoAberta() {
    unsigned tempoInicial = 0;
    unsigned tempoFinal = 0;
    unsigned tempoAberta = 0;
    bool ultimoEstado = false;
    for (porta_t amostra : vetorDados) {

        // Viu que a porta foi aberta -> registra o tempo inicial
        if (amostra.aberta == true && ultimoEstado == false) {
            tempoInicial = amostra.hora;
            ultimoEstado = true;
        } 
        
        // Viu que a porta foi fechada -> registra o tempo inicial
        else if (amostra.aberta == false && ultimoEstado == true) {
            tempoFinal = amostra.hora;
            tempoAberta += tempoFinal - tempoInicial;
            ultimoEstado = false;
        }
    }

    // Terminou aberta -> registra tempo final
    if(ultimoEstado == true)
        tempoAberta += (vetorDados.end()-1)->hora - tempoInicial;

    return tempoAberta;
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