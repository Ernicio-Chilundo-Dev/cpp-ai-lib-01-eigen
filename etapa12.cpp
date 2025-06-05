#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A = (Matrix3d() << 1,2,3,0,1,4,5,6,0).finished();

    cout << "Matriz A:\n"<< A<<endl<<endl;

    cout << "Transpose A:\n" << A.transpose()<<endl;


    return 0;
}