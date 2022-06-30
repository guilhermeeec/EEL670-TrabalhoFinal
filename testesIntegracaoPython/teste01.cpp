// /usr/include/python3.8/Python.h

#include <stdio.h>
#include <Python.h>

int main()
{
	PyObject* pInt;

	Py_Initialize();

	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
	
	Py_Finalize();
	return 0;
}
