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
	//if(pModule) {cout << "funfou" << endl;}

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "getDadosTemp";
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

	//std::cout << result << std::endl;

	return result;
}

string queryDadosPorta() {
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
	//std::cout << "1" << std::endl;

	PyErr_Print();

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	// std::cout << "2" << std::endl;

	// PyErr_Print();

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); // erro aqui na importacao
	//pModule = PyImport_ImportModule(filename);
	// std::cout << "3" << std::endl;

	// PyErr_Print();

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "getDadosPorta";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	// std::cout << "4" << std::endl;

	// PyErr_Print();

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*) "teste"));
	// PyErr_Print();
	// std::cout << "5" << std::endl;

	// PyErr_Print();

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	// std::cout << "6" << std::endl;

	// PyErr_Print();

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	// std::cout << "7" << std::endl;

	// PyErr_Print();

	// std::cout << result << std::endl;

	// PyErr_Print();

	return result;
}

int setDadosPorta(string dadoNovo) {

 
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
	//std::cout << "1" << std::endl;
	//PyErr_Print();

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	// std::cout << "2" << std::endl;
	// PyErr_Print();
	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); // erro aqui na importacao
	//pModule = PyImport_ImportModule(filename);
	// std::cout << "3" << std::endl;
	// PyErr_Print();

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "insertDadosPorta";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	// std::cout << "4" << std::endl;
	// PyErr_Print();

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*) dadoNovo.c_str()));
	// std::cout << "5" << std::endl;

	// PyErr_Print();

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	// std::cout << "6" << std::endl;

	// PyErr_Print();

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	// std::cout << "7" << std::endl;

	// PyErr_Print();

	std::cout << result << std::endl;
	return 0;
}

int setDadosTemperatura(string dadoNovo) {
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

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "insertDadosTemperatura";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	//std::cout << "4" << std::endl;

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*) dadoNovo.c_str()));
	//std::cout << "5" << std::endl;

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	//std::cout << "6" << std::endl;

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	
	//std::cout << "7" << std::endl;

	std::cout << result << std::endl;
	return 0;
}