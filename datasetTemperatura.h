#pragma once
#include "dataset.h"
#include "horario.h"

using namespace std;

struct temperatura_t {
    unsigned id;
    horario_t hora;
    float medida;
};

class DatasetTemperatura : public Dataset {
    public:
        DatasetTemperatura();

        void consultarDados();
        void atualizarDados();
        virtual void exibirDados();
        void exibirEstatisticas(); 
    
    private:
        vector<string> vetorDados;
        vector<temperatura_t> vetorTemperaturas;
        
        float calcularMedia();
        void calcularMaxMin(float&, float&);
        horario_t calcularIntervalo();
};