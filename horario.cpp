#include "horario.h"
#include <iostream>

using namespace std;

horario_t::horario_t(unsigned horas, unsigned minutos) : 
horas(horas), minutos(minutos) {
    ajeitarHorario();
}

unsigned horario_t::getHoras() { return horas; }
unsigned horario_t::getMinutos() { return minutos; }
void horario_t::setHoras(unsigned horas) { this->horas = horas; }
void horario_t::setMinutos(unsigned minutos) { this->minutos = minutos; }

horario_t horario_t::operator+(horario_t& horario2) {
    horario_t horarioFinal(0,0);

    horarioFinal.setHoras(this->horas + horario2.getHoras());
    horarioFinal.setMinutos(this->minutos + horario2.getMinutos());

    horarioFinal.ajeitarHorario();
    return horarioFinal;
}

horario_t horario_t::operator-(horario_t& horarioSubtraendo) {
    horario_t horarioFinal(0,0);

    if(*this < horarioSubtraendo) {
        cout << "Nao e possivel subtrair " << horarioSubtraendo << " de " << *this << endl;
        return horarioFinal;
    }

    unsigned horasMinuendo = this->horas;
    unsigned horasSubtranedo = horarioSubtraendo.getHoras();
    unsigned minutosMinuendo = this->minutos;
    unsigned minutosSubtranedo = horarioSubtraendo.getMinutos();
    
    if(minutosMinuendo < minutosSubtranedo) {
        minutosMinuendo += 60;
        horasMinuendo -= 1;
    }

    horarioFinal.setMinutos(minutosMinuendo-minutosSubtranedo);
    horarioFinal.setHoras(horasMinuendo - horasSubtranedo);
    horarioFinal.ajeitarHorario();
    
    return horarioFinal;
}

void horario_t::ajeitarHorario() {
    if(minutos > 60) {
        unsigned horasAAcrecentar = minutos % 60;
        horas += horasAAcrecentar;
        minutos -= horasAAcrecentar * 60;
    }
}