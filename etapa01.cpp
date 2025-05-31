#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    // Matrix 2 x 2
    Matrix2d A;
    A << 4,1,3,2;
    cout << "Matriz A:\n" <<A<<endl<<endl;

    // Transposta
    cout << "Transposta A:\n" << A.transpose() << endl<<endl;

    // Determinante
    cout << "Determinante A:\n" << A.determinant() << endl<<endl;

    // Inversa (se existir)

    if(A.determinant() != 0){
        cout << "Inversa de A:\n" << A.inverse() <<endl<<endl;
    }else{
        cout << "Matriz nao invertivel!"<<endl<<endl;
    }

    // Vectore
    Vector2cd v;
    v<< 1, 4;
    cout << "Vector de v:\n"<<v<<endl<<endl;

    return 0;
}