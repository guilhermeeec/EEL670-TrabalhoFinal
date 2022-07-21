#include <Python.h>
#include <iostream>

int main()
{
	PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;
	std::cout << "1" << std::endl;

	Py_Initialize();
	atexit(*Py_Finalize);

	// Objeto que representa o arquivo .py
	char filename[] = "pythonTeste";
	pName = PyUnicode_FromString(filename);
	std::cout << "2" << std::endl;

	// Objeto que representa o modulo em Python
	pModule = PyImport_Import(pName); // erro aqui na importacao
	if(pModule) printf("foi\n");
	//pModule = PyImport_ImportModule(filename);
	std::cout << "3" << std::endl;

	// Objeto que representa a funcao chamada "nomeFuncao" do arquivo .py
	char nomeFuncao[] = "nomeFuncao";
	pFunc = PyObject_GetAttrString(pModule, nomeFuncao);
	std::cout << "4" << std::endl;

	// Objeto que representa um argumento chamado pArgs com o valor "Ola"
	pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)"Ola"));
	std::cout << "5" << std::endl;

	// Chama a funcao pFunc com os argumentos pArgs e retorna objeto pValue
	pValue = PyObject_CallObject(pFunc, pArgs);
	std::cout << "6" << std::endl;

	// Transforma em string do C++
	auto result = _PyUnicode_AsString(pValue);
	std::cout << "7" << std::endl;

	std::cout << result << std::endl;
}
