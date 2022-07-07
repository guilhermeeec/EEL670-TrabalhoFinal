#include <string>

using namespace std;

#define DADOS_TEMPERATURA_EXEMPLO   "0,10,29;1,13,32;2,16,21;3,18,27"
#define DADOS_PORTA_EXEMPLO         "0,10,True;1,13,False;2,16,False;3,18,True"

string queryDadosTemperatura();
string queryDadosPorta();
int insertDadosPorta(string);