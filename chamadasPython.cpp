#include <Python.h>
#include <iostream>
#include "chamadasPython.h"

void setupApiPython() {
	Py_Initialize();
	atexit(*Py_Finalize);
}

string queryDadosTemperatura() {
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	PyErr_Print();

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName);
	PyErr_Print();

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "getDadosTemp";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	PyErr_Print();

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)"temp"));
	PyErr_Print();

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	PyErr_Print();

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	PyErr_Print();

	return result;
}

string queryDadosPorta() {
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	PyErr_Print();

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); 
	PyErr_Print();

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "getDadosPorta";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	PyErr_Print();

	// Objeto que representa um argumento chamado pArgs com o valor "teste"
	// "teste" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*) "teste"));
	PyErr_Print();

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	PyErr_Print();

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	PyErr_Print();

	return result;
}

int insertDadosPorta(string dadoNovo) {
	PyObject *pName, *pModule, *pFunc, *pArgs;
	PyErr_Print();

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	PyErr_Print();

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); 
	PyErr_Print();

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "insertDadosPorta";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	PyErr_Print();

	// Objeto que representa um argumento chamado pArgs com o valor "teste"
	// "teste" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*) dadoNovo.c_str()));
	PyErr_Print();

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	PyObject_CallObject(pFunc, pArgs);
	PyErr_Print();

	return 0;
}

int insertDadosTemperatura(string dadoNovo) {
	PyObject *pName, *pModule, *pFunc, *pArgs;

	// Objeto que representa o arquivo .py
	char filename[] = "conexaoFirebase";
	pName = PyUnicode_FromString(filename);
	PyErr_Print();

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); 
	PyErr_Print();

	// Objeto que representa a funcao chamada "getDadosColuna" do arquivo .py
	char nomeFuncao[] = "insertDadosTemperatura";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	PyErr_Print();

	// Objeto que representa um argumento chamado pArgs com o valor "temp"
	// "temp" eh uma coluna da nossa base 
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*) dadoNovo.c_str()));
	PyErr_Print();

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	PyObject_CallObject(pFunc, pArgs);
	PyErr_Print();

	return 0;
}