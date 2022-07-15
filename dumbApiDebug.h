#include <string>

using namespace std;

#define DADOS_TEMPERATURA_EXEMPLO   "0,36000,29;1,46015,32;2,57900,21;3,67523,27"
#define DADOS_PORTA_EXEMPLO         "0,36000,True;1,46015,False;2,57900,False;3,67523,True"

string queryDadosTemperatura();
string queryDadosPorta();
int insertDadosPorta(string);