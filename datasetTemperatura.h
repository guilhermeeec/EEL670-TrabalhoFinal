#pragma once
#include "dataset.h"

using namespace std;

struct temperatura_t {
    unsigned id;
    unsigned hora;
    float medida;
};

class DatasetTemperatura : public Dataset {
    public:
        DatasetTemperatura();

        void consultarDados();
        virtual void exibirDados();
        void exibirEstatisticas(); 
    
    private:
        vector<string> vetorDados;
        vector<temperatura_t> vetorTemperaturas;
        
        float calcularMedia();
        void calcularMaxMin(float&, float&);
        unsigned calcularIntervalo();
};