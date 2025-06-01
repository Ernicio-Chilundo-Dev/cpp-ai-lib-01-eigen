#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace  Eigen;

int main(){
    Matrix3d A = (Matrix3d() << 1,2,3,4,5,6,7,8,9).finished();
    Matrix3d B = (Matrix3d() << 9,8,7,6,5,4,3,2,1).finished();

    Matrix3d resultado = A.cwiseProduct(B);

    cout << "Matriz A:\n" << A <<endl<<endl;
    cout << "Matriz B:\n" << B << "\n\n";
    cout << "Resultado de produto elemento a elemento (A.cwiseProduct(B)):\n" << resultado << "\n\n";

    cout << "Detalhes das multiplicacoes\n";

    for (int i = 0; i < A.rows(); ++i)
    {
        for (int j = 0; j < A.cols(); ++j)
        {
            cout << "A("<< i << "," << j <<") * B("<<i << "," << j << ") = " 
                << A(i,j) << "*" << B(i,j) << " = " << resultado(i,j) << "\n";
        }
        
    }
    

    return 0;
}