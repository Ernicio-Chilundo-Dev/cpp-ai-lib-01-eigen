#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    // Soma das matrizes A e B
    Matrix2d A = (Matrix2d() << 1,2,3,4).finished();
    Matrix2d B = (Matrix2d() << 5,6,7,8).finished();
    Matrix2d C = A + B;

    cout << "Matriz A:\n" << A << "\n\n";
    cout << "Matriz B:\n" << B << "\n\n";
    cout << "Soma A + B:\n" << C << "\n\n";

    return 0;
}