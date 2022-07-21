
######################################################################

# Execute no terminal: python3-config --cflags --embed
COMPILE_FLAGS_2 = -I/usr/include/python3.8 -I/usr/include/python3.8  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.8-YxOiQL/python3.8-3.8.10=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall

# Execute no terminal: python3-config --embed --ldflags
LINK_FLAGS = -L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -L/usr/lib -lpython3.8 -lcrypt -lpthread -ldl  -lutil -lm -lm

######################################################################

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
					 testeMain.cpp 
TESTE_HORARIO_CPP_FILES = horario.cpp testeHorario.cpp excecoes.cpp

APP_CPP_OBJECTS = $(APP_CPP_FILES:.cpp=.o)
TESTE_CHAMADAS_PYTHON_CPP_OBJECTS = $(TESTE_CHAMADAS_PYTHON_CPP_FILES:.cpp=.o)
CORE_DEV_CPP_OBJECTS = $(CORE_DEV_CPP_FILES:.cpp=.o)
TESTE_HORARIO_CPP_OBJECTS = $(TESTE_HORARIO_CPP_FILES:.cpp=.o)

APP_BIN = app
TESTE_CHAMADAS_PYTHON_BIN = teste_chamadas_python
CORE_DEV_BIN = core_dev
TESTE_HORARIO_BIN = teste_horario

COMPILE_FLAGS_1 = -std=c++11 -Wall -I/usr/include/python3.8/

%.o: %.cpp
	g++ $(COMPILE_FLAGS) -c -fPIE $(COMPILE_FLAGS_2)  $<

all:
	make $(APP_BIN) $(TESTE_CHAMADAS_PYTHON_BIN) $(CORE_DEV_BIN) $(TESTE_HORARIO_BIN)

$(APP_BIN): $(APP_CPP_OBJECTS)
	g++ $(APP_CPP_OBJECTS) $(LINK_FLAGS) -o $(APP_BIN)
	
$(TESTE_CHAMADAS_PYTHON_BIN): $(TESTE_CHAMADAS_PYTHON_CPP_OBJECTS)
	g++ $(TESTE_CHAMADAS_PYTHON_CPP_OBJECTS) $(LINK_FLAGS) -o $(TESTE_CHAMADAS_PYTHON_BIN)

$(CORE_DEV_BIN): $(CORE_DEV_CPP_OBJECTS)
	g++ $(CORE_DEV_CPP_OBJECTS) -o $(CORE_DEV_BIN)

$(TESTE_HORARIO_BIN): $(TESTE_HORARIO_CPP_OBJECTS)
	g++ $(TESTE_HORARIO_CPP_OBJECTS) -o $(TESTE_HORARIO_BIN)

clean:
	rm -rf *.o $(APP_CPP_OBJECTS) $(TESTE_CHAMADAS_PYTHON_CPP_OBJECTS) $(CORE_DEV_CPP_OBJECTS) $(TESTE_HORARIO_CPP_OBJECTS)
	rm -rf *.o $(APP_BIN) $(TESTE_CHAMADAS_PYTHON_BIN) $(CORE_DEV_BIN) $(TESTE_HORARIO_BIN)