#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    cout << "Multiplicacao | Matrix * Vetor |"<<endl;

    Matrix2d A = (Matrix2d() << 2,3,4,5).finished();
    Vector2d V = (Vector2d() << 3,6).finished();

    Vector2d resultado1 = A * V;

    cout << "Matriz A:\n" << A << "\n\n";
    cout << "Vetor B:\n" << V << "\n\n";
    cout << "Resultado A * V:\n" << resultado1 << "\n";
    cout << "==========================================================="<<endl;

    cout <<"\nMultiplicao | Matrix * Matriz |"<<endl;
    Matrix2d B = (Matrix2d() << 2,3,4,5).finished();
    Matrix2d resultado2 = A.cwiseProduct(B);
    cout << "A * B:\n" << resultado2 << "\n";
    cout << "==========================================================="<<endl;

    cout << "\nMultiplicacao | Matriz * Escalar |\n";
    Matrix2d resultado3 = 3 * A;// A * 3
    cout << "3 * A:\n" << resultado3 << endl;
    return 0;
}