#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
// Subtracao das matriz A e B
    Matrix2d A = (Matrix2d() << 3,5,7,4).finished();
    Matrix2d B = (Matrix2d() << 1,3,2,0).finished();
    Matrix2d C = A - B;

    cout << "Matriz A:\n" << A <<"\n\n";
    cout << "Matriz B:\n" << B <<"\n\n";
    cout << "Subtracao A - B:\n" << C << "\n\n";

    return 0;
}