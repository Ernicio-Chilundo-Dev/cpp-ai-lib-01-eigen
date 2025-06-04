#include <iostream>
#include <fstream>
#include <sstream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    ifstream arquivo("matriz.txt");

    string linha;

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    int linhas,colunas;
    arquivo >> linhas>> colunas;
    MatrixXd matriz;

    for(int i =0; i< linhas; ++i){
        for (int j = 0; j < colunas; ++j)
        {
            arquivo>>matriz(i,j);
        }
        
    }

    arquivo.close();
    cout << "Matriz carregada com sucesso:\n" << matriz <<endl;


    return 0;
}