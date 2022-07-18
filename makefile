CORE_DEV_CPP_FILES = dataset.cpp \
					 datasetPorta.cpp \
					 datasetTemperatura.cpp \
					 dumbApiDebug.cpp \
					 excecoes.cpp \
					 horario.cpp \
					 main.cpp 
TESTE_HORARIO_CPP_FILES = horario.cpp testeHorario.cpp excecoes.cpp

CORE_DEV_CPP_OBJECTS = $(CORE_DEV_CPP_FILES:.cpp=.o)
TESTE_HORARIO_CPP_OBJECTS = $(TESTE_HORARIO_CPP_FILES:.cpp=.o)

CORE_DEV_BIN = core_dev
TESTE_HORARIO_BIN = teste_horario

%.o: %.cpp
	g++ -Wall -std=c++11 -c $<

all:
	make $(CORE_DEV_BIN) $(TESTE_HORARIO_BIN)

$(CORE_DEV_BIN): $(CORE_DEV_CPP_OBJECTS)
	g++ $(CORE_DEV_CPP_OBJECTS) -o $(CORE_DEV_BIN)

$(TESTE_HORARIO_BIN): $(TESTE_HORARIO_CPP_OBJECTS)
	g++ $(TESTE_HORARIO_CPP_OBJECTS) -o $(TESTE_HORARIO_BIN)

$(BIN): $(CPP_OBJECTS)
	g++ $(CPP_OBJECTS) -o $(BIN)

clean:
	rm -rf *.o $(CORE_DEV_CPP_OBJECTS) $(CORE_DEV_BIN) $(TESTE_HORARIO_CPP_OBJECTS) $(TESTE_HORARIO_BIN)