#include "horario.h"
#include <iostream>
#include <ctime>

using namespace std;

horario_t::horario_t(unsigned horas, unsigned minutos, unsigned segundos) : 
horas(horas), minutos(minutos), segundos(segundos) {
    ajeitarHorario();
}

horario_t::horario_t(unsigned timestamp) {
    horas = minutos = segundos = 0;
    timestampToHorario(timestamp);
}

horario_t::horario_t() {
    getHorarioAtual();
}

unsigned horario_t::getHoras() { return horas; }
unsigned horario_t::getMinutos() { return minutos; }
unsigned horario_t::getSegundos() { return segundos; }
void horario_t::setHoras(unsigned horas) { this->horas = horas; }
void horario_t::setMinutos(unsigned minutos) { this->minutos = minutos; }
void horario_t::setSegundos(unsigned segundos) { this->segundos = segundos; }

horario_t horario_t::operator+(horario_t& horario2) {
    horario_t horarioResultado(0,0,0);

    horarioResultado.setHoras(this->horas + horario2.getHoras());
    horarioResultado.setMinutos(this->minutos + horario2.getMinutos());
    horarioResultado.setSegundos(this->segundos + horario2.getSegundos());

    horarioResultado.ajeitarHorario();
    return horarioResultado;
}

horario_t horario_t::operator-(horario_t& horarioSubtraendo) {
    horario_t horarioFinal(0,0,0);

    if(*this < horarioSubtraendo) throw ExcecaoHorarioInconsistente ();

    unsigned horasMinuendo = this->horas;
    unsigned horasSubtranedo = horarioSubtraendo.getHoras();
    unsigned minutosMinuendo = this->minutos;
    unsigned minutosSubtranedo = horarioSubtraendo.getMinutos();
    unsigned segundosMinuendo = this->segundos;
    unsigned segundosSubtranedo = horarioSubtraendo.getSegundos();

    if(segundosMinuendo < segundosSubtranedo) {
        segundosMinuendo += 60;
        minutosMinuendo -= 1;
    }
    
    if(minutosMinuendo < minutosSubtranedo) {
        minutosMinuendo += 60;
        horasMinuendo -= 1;
    }

    horarioFinal.setHoras(horasMinuendo - horasSubtranedo);
    horarioFinal.setMinutos(minutosMinuendo - minutosSubtranedo);
    horarioFinal.setSegundos(segundosMinuendo - segundosSubtranedo);
    horarioFinal.ajeitarHorario();
    
    return horarioFinal;
}

bool horario_t::operator>(horario_t& segundoHorario) {
    unsigned totalThis = this->getHoras() * 3600 + 
                         this->getMinutos() * 60 +
                         this->getSegundos();
    unsigned totalSegundo = segundoHorario.getHoras() * 3600 + 
                            segundoHorario.getMinutos() * 60 +
                            segundoHorario.getSegundos();
    return totalThis > totalSegundo;
} 

bool horario_t::operator<(horario_t& segundoHorario) {
    unsigned totalThis = this->getHoras() * 3600 + 
                         this->getMinutos() * 60 +
                         this->getSegundos();
    unsigned totalSegundo = segundoHorario.getHoras() * 3600 + 
                            segundoHorario.getMinutos() * 60 +
                            segundoHorario.getSegundos();
    return totalThis < totalSegundo;
} 

bool horario_t::operator==(horario_t& segundoHorario) {
    return !(this->operator>(segundoHorario)) && !(this->operator<(segundoHorario));
} 

void horario_t::ajeitarHorario() {
    if(segundos > 60) {
        unsigned minutosAAcrecentar = (segundos - (segundos % 60)) / 60;
        minutos += minutosAAcrecentar;
        segundos -= minutosAAcrecentar * 60;
    }
    if(minutos > 60) {
        unsigned horasAAcrecentar = (minutos - (minutos % 60)) / 60;
        horas += horasAAcrecentar;
        minutos -= horasAAcrecentar * 60;
    }
}

void horario_t::getHorarioAtual() {
    time_t temporizador;
    time(&temporizador);
    struct tm * horario = localtime(&temporizador);

    horas = (unsigned)horario->tm_hour;
    minutos = (unsigned)horario->tm_min;
    segundos = (unsigned)horario->tm_sec;
}

unsigned horario_t::horarioToTimestamp() {
    return horas*3600 + minutos*60 + segundos; 
}

void horario_t::timestampToHorario(unsigned timestamp) {
    segundos = timestamp;
    ajeitarHorario();
}

ostream& operator<<(ostream& out, horario_t& horario) {
    out << horario.getHoras() << "h"
        << horario.getMinutos() << "m" 
        << horario.getSegundos() << "s";
    return out;
}