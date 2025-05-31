#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    cout << "Parte.1 | Matrix * Vetor |"<<endl;

    Matrix2d A = (Matrix2d() << 2,3,4,5).finished();
    Vector2d V = (Vector2d() << 3,6).finished();

    Vector2d resultado1 = A * V;

    cout << "Matriz A:\n" << A << "\n\n";
    cout << "Vetor B:\n" << V << "\n\n";
    cout << "Resultado A * V:\n" << resultado1 << "\n\n";

    return 0;
}