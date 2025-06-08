#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A;
    A << 12, -51, 4,
         6, 167, -68,
        -4, 24, -41;

        HouseholderQR<Matrix3d> qr(A);
        Matrix3d Q = qr.householderQ();
        Matrix3d R = qr.matrixQR().triangularView<Upper>();

        cout << "Matriz A:\n"<<A<<endl<<endl;
        cout << "Matriz Q (ortogonal):\n"<<Q<<endl<<endl;
        cout << "Matriz R (triangular superior):\n"<<R<<endl<<endl;

        cout << "===============================Cholesky=============================\n";
         Matrix3d B;
        B << 4, 1, 1,
            1, 3, 0,
            1, 0, 2;

        LLT<Matrix3d> lltOfA(B);
        Matrix3d L = lltOfA.matrixL();

        cout << "Matriz B:\n"<<B<<"\n\n";
        cout << "Matriz L (Trriangular inferior):\n"<<L<<"\n\n";
        cout << "Reconstrucao B = L * Lᵗ:\n"<<L * L.transpose()<<endl<<endl;



        cout << "=================================SVD===============================\n";
        MatrixXd C;
        C  << 1, 0, 0,
              0, 1, 0;

        JacobiSVD<MatrixXd> svd(C, ComputeThinU | ComputeThinV);

        cout << "Matriz C:\n"<<C<<"\n\n";
        cout << "Matriz U:\n" << svd.matrixU()<<"\n\n";
        cout << "Valores de sigularidade:\n" << svd.singularValues()<<"\n\n";
        cout << "Matriz Vᵗ:\n" << svd.matrixV().transpose()<<"\n\n";



 return 0;
}