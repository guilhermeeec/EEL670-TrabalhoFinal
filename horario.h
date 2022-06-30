#pragma once
#include <iostream>

using namespace std;

struct horario_t {
    friend ostream& operator<<(ostream&, horario_t&);
    public:
        horario_t(unsigned, unsigned);

        unsigned getHoras();
        unsigned getMinutos();
        void setHoras(unsigned);
        void setMinutos(unsigned);

        bool operator>(horario_t&); // falta implementar
        bool operator<(horario_t&); // falta implementar
        horario_t operator+(horario_t&);
        horario_t operator-(horario_t&);
        
        void ajeitarHorario();  
    
    private:
        unsigned horas;
        unsigned minutos;
};

ostream& operator<<(ostream&, horario_t&); // falta implementar
