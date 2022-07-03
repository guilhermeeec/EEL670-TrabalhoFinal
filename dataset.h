#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Dataset {
    friend ostream& operator<<(ostream&, Dataset*);
    public:
        Dataset();
        
        void consultarDados();
        virtual void exibirDados();
        void exibirEstatisticas(); 

    private:
        vector<string> vetorDados;
};

ostream& operator<<(ostream&, Dataset*);
vector<string> fatiarString(string, string);