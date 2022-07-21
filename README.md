# EEL670-TrabalhoFinal

Requisitos: g++, Python3.8

Execute os seguintes comandos para preparação do ambiente:

sudo apt-get install python3.8-dev
pip install pandas

Toda vez que for reiniciar o ambiente, execute:

export PATH="$PATH:$(pwd)"
export PYTHONPATH="$PYTHONPATH:$(pwd)"

Para configurar o makefile, execute os seguintes comandos:

python3-config --cflags --embed
python3-config --embed --ldflags

Copie o resultado do primeiro comando para a flag COMPILE_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.
Copie o resultado do segundo comando para a flag LINK_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.