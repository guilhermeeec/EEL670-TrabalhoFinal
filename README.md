# EEL670-TrabalhoFinal

Requisitos: g+

1) Execute os seguintes comandos de instalação:

sudo apt-get install python3.8-dev
sudo apt install python3-testresources
pip install pandas
pip install firebase-admin

2) IMPORTANTE: Toda vez que for reiniciar o ambiente, execute:

export PATH="$PATH:$(pwd)"
export PYTHONPATH="$PYTHONPATH:$(pwd)"

3) Para configurar o makefile (apenas da primeira vez), execute os seguintes comandos:

python3-config --cflags --embed
python3-config --embed --ldflags

Copie o resultado do primeiro comando para a flag COMPILE_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.
Copie o resultado do segundo comando para a flag LINK_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.

4) Execute o comando:

make app

para construir a aplicação principal.

5) Execute o comando:

./app 

para executar a aplicação principal.

IMPORTANTE: a aplicação consulta a nuvem, sendo necessário conexão com a Internet