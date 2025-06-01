#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    Matrix3d A = (Matrix3d() << 1,2,3,4,5,6,7,8,9).finished();
    cout << "MatrizA:\n" << A <<endl<<endl;
    cout << "*****************************************************************************"<<endl;

    cout << "Acessar linha 1 (Segunda linha)"<<endl;
    RowVector3d linha = A.row(1);
    cout << "Linha 1:\n" << linha << endl<<endl;

    cout << "*****************************************************************************"<<endl;
    cout << "Acessar coluna 2 (terceira coluna)"<<endl;
    Vector3d coluna = A.col(2);
    cout << "Coluna 2:\n" << coluna << endl;

    cout << "*****************************************************************************"<<endl;

    // Modificar linha 0
    A.row(0) << 10,11,12 ;

    // Multiplicar coluna 1 por 2
    A.col(1) = A.col(1) * 2;

    cout << "Matriz modificada:\n"<< A << endl<<endl;

    cout << "*****************************************************************************"<<endl;

    // Trocar linha 0 por linha 2
    A.row(0).swap(A.row(2));
    cout << "Apos trocar as linhas 0 e 2:\n"<<A<<endl;


    return 0;

}