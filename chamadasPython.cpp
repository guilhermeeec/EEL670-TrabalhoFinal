#include <Python.h>
#include <iostream>
#include "chamadasPython.h"

void setupApiPython() {
	Py_Initialize();
	atexit(*Py_Finalize);
}

string queryDadosTemperatura() {

	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
	//std::cout << "1" << std::endl;

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	//std::cout << "2" << std::endl;

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); // erro aqui na importacao
	//pModule = PyImport_ImportModule(filename);
	//std::cout << "3" << std::endl;
	if(pModule) {cout << "funfou" << endl;}

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "getDadosColuna";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	//std::cout << "4" << std::endl;

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)"temp"));
	//std::cout << "5" << std::endl;

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	//std::cout << "6" << std::endl;

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	//std::cout << "7" << std::endl;

	std::cout << result << std::endl;

	return result;
}

string queryDadosPorta() {
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
	std::cout << "1" << std::endl;

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	std::cout << "2" << std::endl;

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); // erro aqui na importacao
	//pModule = PyImport_ImportModule(filename);
	std::cout << "3" << std::endl;

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "getDadosColuna";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	std::cout << "4" << std::endl;

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)"porta"));
	std::cout << "5" << std::endl;

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	std::cout << "6" << std::endl;

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	std::cout << "7" << std::endl;

	std::cout << result << std::endl;

	return result;
}
