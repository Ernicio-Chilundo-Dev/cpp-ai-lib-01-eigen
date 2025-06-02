#include <iostream>
#include <Eigen/Dense>
#include <limits>

using namespace std;
using namespace Eigen;

void separador(){
    cout << "\n---------------------------------------------------------------------------------\n";
}

void mostrarResultado(const string& titulo, const Matrix3d& resultado){
    separador();
    cout << titulo << ":\n" << resultado << endl;
    separador();
}

