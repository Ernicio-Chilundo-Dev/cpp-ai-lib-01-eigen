#include <iostream>
#include <Eigen/Dense>
#include <limits>

using namespace std;
using namespace Eigen;

void separador(){
    cout << "\n----------------------------------------------------------------------------\n";
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

void menuInterativo(){
    cout << "\n==============================MENU DE OPERACOES================================"
         << "\n1. Soma de (A + B)\n"
         << "\n2. Subtracao de (A - B)\n"
         << "\n3. Produto elemento a elemento (A ⊙ B)\n"
         << "\n4. Multiplicao matricial (A * B)\n"
         << "\n5. Multiplicacao escalar (K * A)\n"
         << "\n0. Sair\n"
         << "\nEscolha uma opcao: ";
}

int main(){
    Matrix3d A = (Matrix3d() << 1,2,3,4,5,6,7,8,9).finished();
    Matrix3d B = (Matrix3d() << 9,8,7,6,5,4,3,2,1).finished();
    int opcao;

    do
    {
        menuInterativo();
        while (!(cin>>opcao))
        {
            cout << "Entrada invalida! Digite um numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcao)
        {
        case 1: somarMatrizes(A,B); break;
        case 2: subtrairMatrizes(A,B); break;
        case 3: produtoElemento(A,B); break;
        case 4: multiplicacaoMatricial(A,B); break;
        case 5: multiplicacaoEscalar(A); break;
        case 0: cout << "Saindo...\n"; break;
        default: cout << "Opcao invalida! Tente  novamente."; break;
        }
        
    } while (opcao !=0);
    

    return 0;
}