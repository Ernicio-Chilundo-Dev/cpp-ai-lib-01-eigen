#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main(){
    Matrix3d A = (Matrix3d()<< 4,-2,1,0,3,-1,0,0,2).finished();

    cout << "Matriz A:\n" << A <<endl<<endl;

    //Calculando Autovalores e Autovetores
    EigenSolver<Matrix3d> solver(A);

    // Autovalres
    cout << "Autovalores:\n"<<solver.eigenvalues()<<endl<<endl;

    //Autovetores
    cout << "Autovetores:\n"<<solver.eigenvectors()<<endl<<endl;

    return 0;
}