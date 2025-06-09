#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

double distancia(const RowVectorXd& a, const RowVectorXd& b) {
    return (a - b).norm();
}

int main() {
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

    // Unir os dados
    MatrixXd dados(6, 2);
    dados << A, B;

    // Centralizar
    RowVectorXd media = dados.colwise().mean();
    MatrixXd centralizado = dados.rowwise() - media;

    // PCA
    MatrixXd cov = (centralizado.adjoint() * centralizado) / double(dados.rows() - 1);
    SelfAdjointEigenSolver<MatrixXd> es(cov);
    MatrixXd componentes = es.eigenvectors().rowwise().reverse();

    // Projetar os dados para 1D
    MatrixXd projetado = centralizado * componentes.leftCols(1); // só 1 componente

    // Separar novamente
    MatrixXd A_proj = projetado.topRows(3);
    MatrixXd B_proj = projetado.bottomRows(3);

    // Calcular centros de cada classe
    RowVectorXd centro_A = A_proj.colwise().mean();
    RowVectorXd centro_B = B_proj.colwise().mean();

    // Nova amostra (fora do treino)
    RowVector2d nova(1.9, 2.5);
    RowVectorXd nova_centralizada = nova - media;
    RowVectorXd nova_proj = nova_centralizada * componentes.leftCols(1);

    // Distâncias
    double dA = distancia(nova_proj, centro_A);
    double dB = distancia(nova_proj, centro_B);

    cout << "📍 Nova amostra projetada: " << nova_proj << "\n";
    cout << "📏 Distância até Classe A: " << dA << "\n";
    cout << "📏 Distância até Classe B: " << dB << "\n";

    if (dA < dB)
        cout << "✅ Classificação: Classe A\n";
    else
        cout << "✅ Classificação: Classe B\n";

    return 0;
}
