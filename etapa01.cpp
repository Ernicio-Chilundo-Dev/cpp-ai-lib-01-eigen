#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    // Matrix 2 x 2
    Matrix2d A;
    A << 4,1,3,2;
    cout << "Matriz A:\n" <<A<<endl<<endl;

    // Transposta
    cout << "Transporta A:\n" << A.transpose() << endl<<endl;

    // Determinante
    cout << "Determinante A:\n" << A.determinant() << endl<<endl;

    return 0;
}