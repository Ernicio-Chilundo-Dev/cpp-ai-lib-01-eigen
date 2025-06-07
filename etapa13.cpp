#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
// Defiinido o sistema
    Matrix2d A;
    Vector2d b;

    A << 2,3,
         5,1;

    b << 8,9;

    // Resolvendo Ax=b
    Vector2d x = A.colPivHouseholderQr().solve(b);
    cout << "Solucao do sistema Ax = b:\n";
    cout << "x = " << x(0)<<endl;
    cout << "y = " << x(1) <<endl;


    return 0;
}