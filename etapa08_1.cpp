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

void somarMatrizes(const Matrix3d& A, const Matrix3d& B){
    mostrarResultado("Resultado A + B", A + B);
}

void subtrairMatrizes(const Matrix3d& A, const Matrix3d& B){
    mostrarResultado("Resultado A - B", A - B);
}

void produtoElemento(const Matrix3d& A, const Matrix3d& B){
    mostrarResultado("Produto elemento a elemento  (A ⊙ B)", A.cwiseProduct(B));
}

void multiplicacaoMatricial(const Matrix3d& A, const Matrix3d& B){
    mostrarResultado("Multiplicacao matricial (A * B)", A * B);
}

void multiplicacaoEscalar(const Matrix3d& A){
    double escalar;
    cout << "Escalar de K: ";
    while (!(cin>>escalar))
    {
        cout << "Entrada invalida! Digite um numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    mostrarResultado("Resultado K * A", escalar * A);
    
}