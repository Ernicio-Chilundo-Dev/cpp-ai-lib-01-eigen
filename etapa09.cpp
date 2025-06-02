#include <iostream>
#include <Eigen/Dense>
#include <fstream>

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A, B,resultado;
    A << 1,2,3,
        4,5,6,
        7,8,9;

    B << 9,8,7,
         6,5,4,
         3,2,1;
    resultado = A + B;
    cout << "Resultado A + B:\n" << A + B << endl;

    ofstream arquivo("resultado.txt"); 

    if(arquivo.is_open()){
        arquivo << "Resultado A + B:\n" << A + B << endl;
        arquivo.close();
        cout << "resultado salvo no resultado\n";
    }else{
        cout << "Erro ao abrir o aquivo\n";
    }
    return 0;
}