#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    Matrix2d A;
    A << 1,2,3,4;
    cout << "Matriz A:\n" <<A<<endl;

    return 0;
}