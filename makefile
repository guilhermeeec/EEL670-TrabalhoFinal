APP_CPP_FILES = dataset.cpp \
				datasetPorta.cpp \
				datasetTemperatura.cpp \
				chamadasPython.cpp \
				excecoes.cpp \
				horario.cpp \
				main.cpp 
TESTE_CHAMADAS_PYTHON_CPP_FILES = chamadasPython.cpp testeChamadasPython.cpp
CORE_DEV_CPP_FILES = dataset.cpp \
					 datasetPorta.cpp \
					 datasetTemperatura.cpp \
					 dumbApiDebug.cpp \
					 excecoes.cpp \
					 horario.cpp \
					 coreDev.cpp 
TESTE_HORARIO_CPP_FILES = horario.cpp testeHorario.cpp excecoes.cpp

APP_CPP_OBJECTS = $(CORE_DEV_CPP_OBJECTS:.cpp=.o)
TESTE_CHAMADAS_PYTHON_CPP_OBJECTS = $(TESTE_CHAMADAS_PYTHON_CPP_FILES:.cpp=.o)
CORE_DEV_CPP_OBJECTS = $(CORE_DEV_CPP_FILES:.cpp=.o)
TESTE_HORARIO_CPP_OBJECTS = $(TESTE_HORARIO_CPP_FILES:.cpp=.o)

APP_BIN = app
TESTE_CHAMADAS_PYTHON_BIN = teste_chamadas_python
CORE_DEV_BIN = core_dev
TESTE_HORARIO_BIN = teste_horario

COMPILE_FLAGS = -std=c++11 -Wall -I/usr/include/python3.8/

%.o: %.cpp
	g++ $(COMPILE_FLAGS) -c -fPIE $(python3-config --cflags --embed) $<

all:
	make $(CORE_DEV_BIN) $(TESTE_HORARIO_BIN)

$(APP_BIN): $(APP_CPP_OBJECTS)
	g++ $(APP_CPP_OBJECTS) $(python3-config --embed --ldflags) -o $(APP_BIN)
	
$(TESTE_CHAMADAS_PYTHON_BIN): $(TESTE_CHAMADAS_PYTHON_CPP_OBJECTS)
	g++ $(TESTE_CHAMADAS_PYTHON_CPP_OBJECTS) $(python3-config --embed --ldflags) -o $(TESTE_CHAMADAS_PYTHON_BIN)

$(CORE_DEV_BIN): $(CORE_DEV_CPP_OBJECTS)
	g++ $(CORE_DEV_CPP_OBJECTS) -o $(CORE_DEV_BIN)

$(TESTE_HORARIO_BIN): $(TESTE_HORARIO_CPP_OBJECTS)
	g++ $(TESTE_HORARIO_CPP_OBJECTS) -o $(TESTE_HORARIO_BIN)

clean:
	rm -rf *.o $(APP_CPP_OBJECTS) $(TESTE_CHAMADAS_PYTHON_CPP_OBJECTS) $(CORE_DEV_CPP_OBJECTS) $(TESTE_HORARIO_CPP_OBJECTS)
	rm -rf *.o $(APP_BIN) $(TESTE_CHAMADAS_PYTHON_BIN) $(CORE_DEV_BIN) $(TESTE_HORARIO_BIN)