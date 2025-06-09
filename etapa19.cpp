#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    //Exemplo de dados com 6 amostras e 2 features
    MatrixXd dados(6,2);
    dados << 2.5, 2.4,
             0.5, 0.7,
             2.2, 2.9,
             1.9, 2.2,
             3.1, 3.0,
             2.3, 2.7;

    cout << "Dados originais:\n" << dados << endl;

    //Passo 1 centralizar os dados (subtrair a media)
    RowVectorXd media = dados.colwise().mean();
    MatrixXd centralizado = dados.rowwise() - media;

    //Passo 2: calcular a matriz da covariancia
    MatrixXd cov = (centralizado.adjoint() * centralizado) / double(dados.rows() -1);

    //Passo 3: calcular autovalores e autovetores
    SelfAdjointEigenSolver <MatrixXd> es(cov);
    MatrixXd autovetores = es.eigenvectors().rowwise().reverse();
    VectorXd autovalores = es.eigenvalues().reverse();

    return 0;
}