#include "dataset.h"
#include "datasetTemperatura.h"

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
    DatasetTemperatura dadosTemperatura;

    while(true) {
        imprimeMenu();
        std::cout << "\nOpcao[1-5/0]: ";
        std::string entradaUsuario;
        getline(std::cin, entradaUsuario);
        unsigned opcao = (unsigned)strtoul(entradaUsuario.c_str(), NULL, 10);
        
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
            break;

            case 4:
            break;

            case 5:
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
