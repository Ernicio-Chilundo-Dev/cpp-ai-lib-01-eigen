#include <iostream>
#include <fstream>
#include <sstream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    ifstream arquivo("resultado.txt");
    string linha;
    Matrix3d matrizLida;
    int i = 0;

    if (arquivo.is_open()){
        getline(arquivo, linha);
        while (getline(arquivo, linha) && i < 3)
        {
            stringstream ss(linha);
            double val1, val2, val3;
            ss >> val1 >> val2 >> val3;

            matrizLida(i, 0) = val1;
            matrizLida(i, 1) = val2;
            matrizLida(i, 2) = val3;

            i++;
        }

        arquivo.close();
        cout << "Matriz linda com sucesso:\n"<< matrizLida<< endl;
        
    }else{
        cout << "Erro ao abrir o arquivo!"<< endl;
    }
    return 0;
}