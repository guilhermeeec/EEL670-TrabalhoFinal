#include "datasetTemperatura.h"
#include "dumbApiDebug.h"
#include <iomanip>

DatasetTemperatura::DatasetTemperatura() :
Dataset(), vetorTemperaturas(0) { consultarDados(); }

void DatasetTemperatura::consultarDados() {
    string dadosRetornados = queryDadosTemperatura();
    vector<string> dados = fatiarString(dadosRetornados, ";");

    for(string dado : dados) {
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

void DatasetTemperatura::exibirEstatisticas() {} 