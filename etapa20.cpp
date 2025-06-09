#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

double distancia(const RowVectorXd& a, RowVectorXd& b){
    return (a - b).norm();
}

int mai(){


    return 0;
}