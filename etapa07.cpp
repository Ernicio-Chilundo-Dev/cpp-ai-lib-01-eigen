#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){

    Matrix3d A = (Matrix3d() << 1,2,3,4,5,6,7,8,9).finished();
    Matrix3d B = (Matrix3d() << 9,8,7,6,5,4,3,2,1).finished();

    Matrix3d soma = A + B;

    cout << "Matriz A:\n" << A << "\n\n";
    cout << "Matriz B:\n" << B << "\n\n";
    cout << "Soma A + B:\n" << soma << "\n\n";
    return 0;
}