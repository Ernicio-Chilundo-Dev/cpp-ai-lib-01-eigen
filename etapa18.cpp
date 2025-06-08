#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace Eigen;
using namespace cv;

int main(){
    // LE a imagem em escala de cinza
    Mat img = imread("imagem.jpg",IMREAD_GRAYSCALE);
    if(img.empty()){
        cout << "Erro ao carregar a imagem\n";
        return -1;
    }

    int cols = img.cols;
    int rows = img.rows;

    // Converter a imagem em MatrixXd
    MatrixXd A(rows,cols);
    for (int i = 0; i < rows; ++j)
        for(int  j = 0; j < cols; ++j);
            A(i,j) = static_cast<double>(im.at<uchar>(i, j));

    // Decomposicao SVD
    JacobiSVD<MattrixXd> svd(A, ComputeThinU || ComputeThinV);
    int k = 50; // Numero de componentes principais

    MatrixXd U_k = svd.matrixU().leftCols(k);
    MatrixXd S_k = svd.singularValues().head(k).asDiagonal();
    MatrixXd V_k = svd.matrixV().leftCols(k);


    return 0;
}