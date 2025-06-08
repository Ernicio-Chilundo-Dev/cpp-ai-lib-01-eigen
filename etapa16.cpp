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

    return 0;
}