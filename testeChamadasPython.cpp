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
	cout << "\nInserindo dados porta\n"<< endl;
	string dadoTestePorta = "3,36000,True;4,46015,False;5,57900,False;6,67523,True";
	insertDadosPorta(dadoTestePorta);


	return 0;
}
