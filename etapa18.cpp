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

    // Reconstrucao aproximada
    MatrixXd A_reconstruida = U_k * S_k * V_k.transpose();

    // Norrmaliza os valores para 0-255
    A_reconstruida = A_reconstruida.cwiseMax(0).cwiseMin(255);

    // Converte para imagem openCV 
    Mat img_out(rows,cols, CV_8U);
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            img_out.at<uchar>(i,j)=static_cast<uchar>(A_reconstruida(i,j));

    imwrite("imagem_comprimida.jpg",img_out);
    cout << "Imagem comprimida salva como 'imagem_comprimida.jpg'\n";

    return 0;
}