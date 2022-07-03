#pragma once
#include <exception>

using namespace std;

class ExcecaoDivisaoPorZero : public exception {
    public: 
        ExcecaoDivisaoPorZero();
        virtual const char* what() const throw();
};

class ExcecaoHorarioInconsistente : public exception {
    public: 
        ExcecaoHorarioInconsistente();
        virtual const char* what() const throw();
};