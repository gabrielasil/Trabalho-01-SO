#include<iostream>
using std::cout;
using std::endl;
#include <chrono>
#include <vector>
#include <fstream>
using std::ofstream;
#include <cstdlib>
using namespace std;
#include <string>
#include <stdio.h>

/*
void sequencial(FILE* matrizes){    

}
*/

int main(int argc, char *argv[]){
    string arq1, arq2, linha;
    char num;
    arq1 = argv[1];
    int l1{0}, c1{0}, l2{0}, c2{0}, n, pos{0};
    arq2 = argv[2];
    fstream arquivo1;
    fstream arquivo2;
    //fstream arquivo3;
    //abre o arquivo 1
    arquivo1.open(arq1, ios::in); 

    if (!arquivo1) {
		cout << "No such file";
	}

    //le o arquivo 1
    vector<vector<int>> matriz1;
    if(arquivo1.is_open()){
        while(arquivo1){
            //le uma linha do arquivo e coloca em string
            std::getline(arquivo1, linha);
            matriz1.push_back(vector<int>());
            c1 = 0;
            while(linha[pos]!='\0'){
                if(linha[pos]!=' '){
                    num = linha[pos];
                    n = atoi(&num);
                    matriz1[l1].push_back(n);
                    //std::cout<<matriz1[l1][c1]<< " ";
                    //fflush(stdout);
                    c1++;
                }
                pos++;
            }
            pos = 0;
            //std::cout<<endl;
            l1++;
        }
    }

    arquivo2.open(arq2, ios::in); 

    if (!arquivo2) {
		cout << "No such file";
	}
    pos = 0;
    vector<vector<int>> matriz2;
    if(arquivo2.is_open()){
        while(arquivo2){
            //le uma linha do arquivo e coloca em string
            std::getline(arquivo2, linha);
            matriz2.push_back(vector<int>());
            c2 = 0;
            while(linha[pos]!='\0'){
                if(linha[pos]!=' '){
                    num = linha[pos];
                    n = atoi(&num);
                    matriz2[l2].push_back(n);
                    //std::cout<<matriz2[l2][c2]<< " ";
                    //fflush(stdout);
                    c2++;
                }
                pos++;
            }
            pos = 0;
            //std::cout<<endl;
            l2++;
        }
    }

    //inicia a marcacao do tempo
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    //cria matriz resultado
    vector<vector<int>> res;
    size_t tam{matriz1.size()-1};
    for (size_t i = 0; i <tam; ++i) {
        res.push_back(vector<int>());
        for (size_t j = 0; j <tam; ++j) {
            res[i].push_back(0);
            for (size_t k = 0; k < tam; ++k) {
                res[i][j] += matriz1[i][k] * matriz2[k][j];
                
            }
            //std::cout<<res[i][j]<<" ";
        }
        //std::cout<<endl;
    }
    //finaliza a marcacao do tempo
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Tempo " <<chrono::duration_cast<chrono::microseconds>(end - begin).count() << "(ms)" <<endl;

    arquivo1.close();
    arquivo2.close();
    //abre arquivo para anotar os tempos
    std::ofstream outfile;
    outfile.open("/root/Fernanda/TI-2021.2/SO/trabalho-01/Trabalho-01-SO/tempos", std::ios_base::app); 
    //arquivo3.open("tempos", ios::in); 

    outfile<<tam<<" x "<<tam<<": ";
    outfile<<chrono::duration_cast<chrono::microseconds>(end - begin).count() << "(ms)" <<endl;

    
}