#include <iostream>
#include <Python.h>
#include "chamadasPython.h"

int main()
{
    setupApiPython();
	string dadosTemperatura = queryDadosTemperatura();
	cout << dadosTemperatura << endl;
	string dadosPorta = queryDadosPorta();
	cout << dadosPorta << endl;
	cout << "Inserindo dados porta"<< endl;

	string dadoTestePorta = "6,36000,True;7,46015,False;8,57900,False;9,67523,True";
	cout << "Cheguei aqui" << endl; 
	setDadosPorta(dadoTestePorta);
	cout << "Cheguei aqui tb" << endl;

	return 0;
}
