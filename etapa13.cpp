#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
// Defiinido o sistema
    Matrix2d A;
    Vector2d b;

    A << 1,3,
         5,2;

    b << 8,9;

    return 0;
}