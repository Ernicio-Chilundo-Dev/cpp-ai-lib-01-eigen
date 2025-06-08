#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A;
      Matrix3d A;
    A << 12, -51, 4,
         6, 167, -68,
        -4, 24, -41;

        HouseholderQR<Matrix3d> qr(A);
        Matrix3d Q = qr.householderQ();
        Matrix3d R = qr.matrixQR().triangularView<Upper>();

        cout << "Matriz A:\n"<<A<<endl<<endl;
        cout << "Matriz Q (ortogonal):\n"<<Q<<endl<<endl;
        cout << "Matriz R (triangular superior):\n"<<R<<endl<<endl;
    return 0;
}