#include "datasetPorta.h"
#include "excecoes.h"
#include "dumbApiDebug.h"
#include "chamadasPython.h"
#include <iomanip>

DatasetPorta::DatasetPorta() :
Dataset(), vetorDados(0) { consultarDados(); }

void DatasetPorta::consultarDados() {

    // dadosRetornados: "0,36000,True;1,46015,False;2,57900,False;3,67523,True"
    string dadosRetornados = queryDadosPorta();

    // dados: ["0,36000,True" "1,46015,False" "2,57900,False" "3,67523,True"]
    vector<string> dados = fatiarString(dadosRetornados, ";");

    for(string dado : dados) {

        // campos: ["0" "36000" "True"]
        vector<string> campos = fatiarString(dado, ",");

        unsigned id = (unsigned)stoul(campos[0],nullptr);
        unsigned timestamp = (unsigned)stoul(campos[1],nullptr);
        bool aberta = (campos[2] == "True" ? true : false);

        horario_t horario(timestamp);

        porta_t amostra;
        amostra.id = id;
        amostra.hora = horario;
        amostra.aberta = aberta;

        vetorDados.push_back(amostra);
    }
}

void DatasetPorta::atualizarDados() {
    vetorDados.clear();
    consultarDados();
}

void DatasetPorta::publicarDados(string dado) {
    insertDadosPorta(dado);
}

void DatasetPorta::exibirDados() {
    cout << left << setw(9) << "ID" 
         << left << setw(15) << "Horario" 
         << left << setw(15) << "Estado" << endl;
    for (porta_t amostra : vetorDados) {
        string textoEstado =  (amostra.aberta ? "Aberta" : "Fechada");
        cout << left << setw(9) << amostra.id 
             << left << setw(15) << amostra.hora 
             << left << setw(15) << textoEstado << endl;
    }
}

void DatasetPorta::exibirEstatisticas() {
    horario_t tempoAberta = this->calcularTempoAberta();
    horario_t intervalo = calcularIntervalo();
    horario_t tempoFechada = intervalo - tempoAberta;

    cout << left << setw(25) << "Estatistica" << "Valor" << endl;
    cout << left << setw(25) << "Tempo aberta" << tempoAberta << endl;
    cout << left << setw(25) << "Tempo fechada" << tempoFechada << endl;
    cout << left << setw(25) << "Intervalo" << intervalo << endl;
} 

void DatasetPorta::abrirFecharPorta() {
    bool abertaNoMomento = (vetorDados.end()-1)->aberta;
    unsigned ultimoId = (vetorDados.end()-1)->id;
    horario_t ultimoHorario = (vetorDados.end()-1)->hora;

    horario_t horarioAtual;

    porta_t novoDado;
    if(ultimoHorario > horarioAtual) {
        cout << "O ultimo dado foi inserido em uma hora anterior.\n"
             << "Ajustando o horario do novo dado para manter ordem." << endl;
        novoDado.hora = ultimoHorario;
    } else
        novoDado.hora = horarioAtual;
    
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
    string horaString(to_string(novoDado.hora.horarioToTimestamp()));
    string boolString = novoDado.aberta ? "True" : "False";
    string dado(idString + "," + horaString + "," + boolString);

    publicarDados(dado);
    cout << "Publicacao realizada com sucesso." << endl;
}

horario_t DatasetPorta::calcularTempoAberta() {
    horario_t tempoInicial(0);
    horario_t tempoFinal(0);
    horario_t tempoAberta(0);
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
            horario_t tempoDecorrido(0);
            tempoDecorrido = tempoFinal - tempoInicial;
            tempoAberta = tempoAberta + tempoDecorrido;
            ultimoEstado = false;
        }
    }

    // Terminou aberta -> registra tempo final
    if(ultimoEstado == true) {
        horario_t tempoDecorrido(0);
        tempoDecorrido = (vetorDados.end()-1)->hora - tempoInicial;
        tempoAberta = tempoAberta + tempoDecorrido;
    }

    return tempoAberta;
}

horario_t DatasetPorta::calcularIntervalo() {
    vector<porta_t>::iterator it_inicio = vetorDados.begin();
    porta_t primeiraAmostra = *it_inicio;
    horario_t tempoInicial = primeiraAmostra.hora;

    vector<porta_t>::iterator it_fim = vetorDados.end()-1;
    porta_t ultimaAmostra = *it_fim;
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