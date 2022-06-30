#pragma once
#include "dataset.h"

using namespace std;

class DatasetPorta : public Dataset {
    public:
        DatasetPorta();
        void consultarDados();
        void publicarDados(int);
        virtual void exibirDados(ostream&);
        void exibirEstatisticas(); 
        void abrirFecharPorta();
    
    private:
        vector<string> vetorDados;
};