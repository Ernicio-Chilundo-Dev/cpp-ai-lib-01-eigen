#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A,B;
    double escalar;
    int opcao;

    A << 1,2,3,
         4,5,6,
         7,8,9;

    B << 9,8,7,
         6,5,4,
         3,2,1;

    do
    {
        cout << "=============== MENU DE OPERACOES ==============="<< endl<<endl
             << "1. Soma (A + B)\n"
             << "2. Subtracao (A - B)\n"
             << "3. Produto elemento a elemento (A ⊙ B)\n"
             << "4. Multiplicao matricial (A * B)\n"
             << "5. Multiplicao escalar (K * A)\n"
             << "0. Sair do programa\n"
             << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Resultado de A + B:\n" << A + B <<endl;
            break;
        case 2:
            cout << "Resultado de A - B:\n" << A - B <<endl;
            break;
        case 3:
            cout << "Produto elemento a elemento:\n" << A.cwiseProduct(B) <<endl;
            break;
        case 4:
            cout << "Multiplicao matricial:\n" << A * B << endl;
            break;
        case 5:
            cout << "Escalar: ";
            cin >> escalar;
            cout << "Multiplicao escalar K * A:\n" << escalar * A << endl;
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida! Tente novamente.\n";
            break;
        }

    } while (opcao != 0);
    

    return 0;
}