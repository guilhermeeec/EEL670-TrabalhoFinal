#include <string>

using namespace std;

#define DADOS_TEMPERATURA_EXEMPLO   "0,4507,29;1,7200,32;2,12235,21;3,12491,27"
#define DADOS_PORTA_EXEMPLO         "0,4507,True;1,7200,False;2,12235,False;3,12491,True"

string queryDadosTemperatura();
string queryDadosPorta();
int insertDadosPorta(string);