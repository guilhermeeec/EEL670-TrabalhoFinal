#include "horario.h"

int main() {
    horario_t tempo1(15,24,50);
    horario_t tempo2(15,26,30);
    cout << "t1 = " << tempo1 << "\n" << "t2 = " << tempo2 << endl;

    tempo1 > tempo2 ? cout << "t2 > t1" << endl : cout << "t2 < t1" << endl;
    tempo1.setMinutos(78);
    tempo1.ajeitarHorario();
    tempo1 < tempo2 ? cout << "t2 < t1" << endl : cout << "t2 > t1" << endl;
    
    cout << "t1 = " << tempo1 << "\n" << "t2 = " << tempo2 << endl;
    horario_t tempoSoma = tempo2 + tempo1;
    cout << "t2 + t1 = " << tempoSoma << endl;
    horario_t tempoDiferenca21(0,0,0);
    try {
        tempoDiferenca21 = tempo2 - tempo1; 
    } catch (ExcecaoHorarioInconsistente& excecao) {
        cerr << excecao.what() << "Nao e possivel fazer " << tempo2 << " - " << tempo1 << endl;  
    }
    cout << "t2 - t1 = " << tempoDiferenca21 << endl;
    horario_t tempoDiferenca12 = tempo1 - tempo2;
    cout << "t1 - t2 = " << tempoDiferenca12 << endl;
    
    return 0;
}