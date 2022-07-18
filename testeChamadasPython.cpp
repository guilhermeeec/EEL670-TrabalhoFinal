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
	return 0;
}
