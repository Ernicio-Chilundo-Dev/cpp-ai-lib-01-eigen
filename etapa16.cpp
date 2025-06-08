#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    MatrixXd A(5,5);

        A << 1,2,3,4,5,
             5,4,3,2,1,
             2,3,4,3,2,
             1,1,1,1,1,
             0,1,0,1,0;

    cout << "Matriz Original (simulado uma imagem):\n" << A << "\n\n";

    // Decomposicao SVD
    JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV);
    auto U = svd.matrixU();
    auto S = svd.singularValues().asDiagonal();
    auto vt = svd.matrixV().transpose();

    // Compressao com apenas os dois maires valores sigulares
    MatrixXd U2 = U.leftCols(2);
    MatrixXd S2 = S.topLeftCorner(2, 2);
    MatrixXd vt2 = vt.topRows(2);
    
    MatrixXd A_aprox = U2 * S2 * vt2;
    cout << "Matriz aproximada (compressao com 2 componentes):\n" << A_aprox << "\n\n";
    return 0;
}