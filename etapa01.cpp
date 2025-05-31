#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(){
    // Matrix 2 x 2
    Matrix2d A;
    A << 1,2,3,4;
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
    Vector2d v;
    v<< 1, 2;
    cout << "Vector de v:\n"<<v<<endl<<endl;

    // Multiplicacao matriz * vector

    Vector2d resultado = A * v;
    

    cout << "A * v=\n" << resultado << endl<<endl;

    return 0;
}