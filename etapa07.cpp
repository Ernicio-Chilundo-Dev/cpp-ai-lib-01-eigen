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

    cout << "Detalhes das somas:"<<endl;

    for (int i = 0; i < A.rows(); ++i)
    {
        for (int j = 0; j < A.cols() ; ++j)
        {
            cout << "A("<<i<<","<<j<<") + B("<<i<<","<<j<<") = "
                << A(i,j)  << " + " << B(i,j) << "  = " <<  soma(i,j)<<"\n";
        }
        
    }
    
    return 0;
}