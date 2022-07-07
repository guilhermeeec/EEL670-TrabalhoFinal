#pragma once
#include "dataset.h"

using namespace std;

struct porta_t {
    unsigned id;
    unsigned hora;
    bool aberta;
};

class DatasetPorta : public Dataset {
    public:
        DatasetPorta();

        void consultarDados();
        void publicarDados(string);
        virtual void exibirDados();
        void exibirEstatisticas(); 

        void abrirFecharPorta();
    
    private:
        vector<porta_t> vetorDados;
        unsigned calcularTempoAberta(); 
        unsigned calcularIntervalo(); 
};