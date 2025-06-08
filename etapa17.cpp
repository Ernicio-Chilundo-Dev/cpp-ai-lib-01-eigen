#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    int linhas, colunas;

    cout << "Digite o numero de linhas da matriz: ";
    cin >> linhas;
    cout << "Digite o numero de colunas da matriz: ";
    cin >> colunas;

    MatrixXd A(linhas,colunas);
    cout << "Digite os elementos da matriz linha por linha:\n";

    for (int i = 0; i < linhas; ++i)
    {
        for(int j = 0; j < colunas; ++j){
            cout << "A("<<i<<","<<j<<"): ";
            cin >> A(i,j);
        }
    }
    
    cout << "Matriz A:\n"<< A<<endl<<endl;

    //Decomposicao SVD
    JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV);

    auto U = svd.matrixU();
    auto S = svd.singularValues().asDiagonal();
    auto Vt = svd.matrixV();

    int k;
    cout << "Quantos valores singulares voce quer usar para a reconstrucao: ";
    cin >> k;

    if(k <=0 || k>S.rows()){
        cout << "Numero invalido. Usando todos valores singulares.\n";
        k=S.rows();
    }

    MatrixXd U_k = U.leftCols(k);
    MatrixXd S_k = S.topLeftCorner(k, k);
    MatrixXd Vt_k = Vt.topRows(k);
    MatrixXd A_prox = U_k * S_k * Vt_k;

    cout << "Matriz reconstruida com "<< k<< " componentes:\n"<<A_prox<<endl;



    return 0;
}