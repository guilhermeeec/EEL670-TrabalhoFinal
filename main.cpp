#include "dataset.h"
#include "datasetTemperatura.h"
#include "datasetPorta.h"
#include "chamadasPython.h"

void imprimeMenu() {
    //system("cls");
    std::cout <<         "-----------------------------------" 
              << "\n" << "   Bem-vindo ao IOTPy++  " 
              << "\n" << "Selecione a opcao: "
              << "\n" << "1- Exibir dados de temperatura"    
              << "\n" << "2- Exibir estatisticas de temperatura"                
              << "\n" << "3- Exibir dados de porta"   
              << "\n" << "4- Exibir estatisticas de porta"   
              << "\n" << "5- Abrir/Fechar porta"   
              << "\n" << "0- Sair" << std::endl;
}

int main() {
    setupApiPython();

    DatasetTemperatura dadosTemperatura;
    DatasetPorta dadosPorta;

    while(true) {
        imprimeMenu();
        std::cout << "\nOpcao[1-5/0]: ";

        std::string entradaUsuario;
        getline(std::cin, entradaUsuario);
        unsigned opcao = (unsigned)strtoul(entradaUsuario.c_str(), NULL, 10);

        cout << "Sincronizando..." << endl;
        dadosTemperatura.atualizarDados();
        dadosPorta.atualizarDados();
        
        switch (opcao) {
           case 0:
            return 0;
            break;

            case 1:
            cout << &dadosTemperatura << endl;
            break;

            case 2:
            dadosTemperatura.exibirEstatisticas();
            break;

            case 3:
            cout << &dadosPorta << endl;
            break;

            case 4:
            dadosPorta.exibirEstatisticas();
            break;

            case 5:
            dadosPorta.abrirFecharPorta();
            break;

            default:
            std::cout << "Opcao invalida." << std::endl;
            break;
        } // end switch
        std::cout << "Pressione qualquer tecla para continuar" << std::endl;
        getline(std::cin, entradaUsuario);
    } // end while
    return 0;
}
