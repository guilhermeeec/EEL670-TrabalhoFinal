# EEL670-TrabalhoFinal

Requisitos: g++, Python3.8

Execute os seguintes comandos para preparação do ambiente:

sudo apt-get install python3.8-dev
export PATH="$PATH:[caminho/EEL670-TrabalhoFinal]"
export PYTHONPATH="$PYTHONPATH:[caminhoEEL670-TrabalhoFinal]"

Substitua [caminhoEEL670-TrabalhoFinal] pelo path deste repositorio na máquina.

Para configurar o makefile, execute os seguintes comandos:

python3-config --cflags --embed
python3-config --embed --ldflags

Copie o resultado do primeiro comando para a flag COMPILE_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.
Copie o resultado do segundo comando para a flag LINK_FLAGS_2 = [...], substituindo 
o [...] pelo resultado do comando.