# EEL670-TrabalhoFinal

Requisitos: g++, Python3.8

Execute os seguintes comandos para preparação do ambiente:

sudo apt-get install python3.8-dev
sudo apt install python3-testresources
pip install pandas
pip install firebase-admin

Toda vez que for reiniciar o ambiente, execute:

export PATH="$PATH:$(pwd)"
export PYTHONPATH="$PYTHONPATH:$(pwd)"

Para configurar o makefile (apenas da primeira vez), execute os seguintes comandos:

python3-config --cflags --embed
python3-config --embed --ldflags

Copie o resultado do primeiro comando para a flag COMPILE_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.
Copie o resultado do segundo comando para a flag LINK_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.