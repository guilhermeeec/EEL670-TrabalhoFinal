#pragma once
#include <iostream>
#include "excecoes.h"

using namespace std;

struct horario_t {
    friend ostream& operator<<(ostream&, horario_t&);
    public:
        horario_t(unsigned, unsigned, unsigned);

        unsigned getHoras();
        unsigned getMinutos();
        unsigned getSegundos();
        void setHoras(unsigned);
        void setMinutos(unsigned);
        void setSegundos(unsigned);

        bool operator>(horario_t&); 
        bool operator<(horario_t&); 
        bool operator==(horario_t&); 
        horario_t operator+(horario_t&);
        horario_t operator-(horario_t&);
        
        void ajeitarHorario();  
    
    private:
        unsigned horas;
        unsigned minutos;
        unsigned segundos;
};

ostream& operator<<(ostream&, horario_t&); 
