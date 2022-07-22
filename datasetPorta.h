#pragma once
#include "dataset.h"
#include "horario.h"

using namespace std;

struct porta_t {
    unsigned id;
    horario_t hora;
    bool aberta;
};

class DatasetPorta : public Dataset {
    public:
        DatasetPorta();

        void consultarDados();
        void atualizarDados();
        void publicarDados(string);
        virtual void exibirDados();
        void exibirEstatisticas(); 

        void abrirFecharPorta();
    
    private:
        vector<porta_t> vetorDados;
        horario_t calcularTempoAberta(); 
        horario_t calcularIntervalo(); 
};