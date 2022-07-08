CORE_DEV_CPP_FILES = dataset.cpp \
					 datasetTemperatura.cpp \
					 datasetPorta.cpp \
					 dumbApiDebug.cpp \
					 excecoes.cpp \
					 main.cpp

CORE_DEV_CPP_OBJECTS = $(CORE_DEV_CPP_FILES:.cpp=.o)

CORE_DEV_BIN = core_dev

%.o: %.cpp
	g++ -Wall -std=c++11 -c $<

all:
	make $(CORE_DEV_BIN)

$(CORE_DEV_BIN): $(CORE_DEV_CPP_OBJECTS)
	g++ $(CORE_DEV_CPP_OBJECTS) -o $(CORE_DEV_BIN)

$(BIN): $(CPP_OBJECTS)
	g++ $(CPP_OBJECTS) -o $(BIN)

clean:
	rm -rf *.o $(CORE_DEV_CPP_OBJECTS) $(CORE_DEV_BIN)