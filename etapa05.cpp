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


    return 0;

}