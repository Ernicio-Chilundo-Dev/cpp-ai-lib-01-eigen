#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A = (Matrix3d() << 1,2,3,0,1,4,5,6,0).finished();

    cout << "Matriz A:\n"<< A<<endl<<endl;

    cout << "Transpose A:\n" << A.transpose()<<endl<<endl;

    double det = A.determinant();
    cout << "Determinante A:\n" << det << "\n\n";

    if (det !=0){
        cout << "Inversa A:\n"  << A.inverse() << "\n\n";
    }else{
        cout << "Matriz nao invertivel";
    }

    FullPivLU<Matrix3d> lu_decomp(A);
    cout << "Posto (rank) de A:\n" <<  lu_decomp.rank() << "\n\n";

    return 0;
}