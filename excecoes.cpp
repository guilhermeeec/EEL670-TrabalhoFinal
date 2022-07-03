#include "excecoes.h"

ExcecaoDivisaoPorZero::ExcecaoDivisaoPorZero() : exception() {}

const char* ExcecaoDivisaoPorZero::what() const throw() { 
    return "ExcecaoDivisaoPorZero disparada: ";
}

ExcecaoHorarioInconsistente::ExcecaoHorarioInconsistente() : exception() {}

const char* ExcecaoHorarioInconsistente::what() const throw() { 
    return "ExcecaoHorarioInconsistente disparada: ";
}