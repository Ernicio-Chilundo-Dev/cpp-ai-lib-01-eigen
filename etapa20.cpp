#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

double distancia(const RowVectorXd& a, RowVectorXd& b){
    return (a - b).norm();
}

int mai(){
      // Classe A (3 amostras 2D)
    MatrixXd A(3, 2);
    A << 2.5, 2.4,
         2.2, 2.9,
         2.3, 2.7;

    // Classe B (3 amostras 2D)
    MatrixXd B(3, 2);
    B << 0.5, 0.7,
         1.0, 1.1,
         0.8, 0.6;

    // Unir dados
    MatrixXd dados(6,2);
    dados << A, B;

    // centralizar
    RowVectorXd media = dados.colwise().mean();
    MatrixXd centralizado = dados.rowwise() - media;

    // PCA 
    MatrixXd cov = (centralizado.adjoint() * centralizado) / double(dados.rows() -1);
    SelfAdjointEigenSolver <MatrixXd> es(cov);
    MatrixXd componentes =es.eigenvectors().rowwise().reverse();

    // Projetar os dados 1D
    MatrixXd projetado = centralizado * componentes.leftCols(1);
    

    // Separar novamente 
    MatrixXd A_proj = projetado.topRows(3);
    MatrixXd B_proj = projetado.bottomRows(3);

    
}