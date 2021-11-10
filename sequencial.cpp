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
                    std::cout<<matriz1[l1][c1]<< " ";
                    //fflush(stdout);
                    c1++;
                }
                pos++;
            }
            pos = 0;
            std::cout<<endl;
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
                    std::cout<<matriz2[l2][c2]<< " ";
                    //fflush(stdout);
                    c2++;
                }
                pos++;
            }
            pos = 0;
            std::cout<<endl;
            l2++;
        }
    }



    /*
    int n1,m1,n2,m2;
    n1 = atoi(argv[1]);
    m1 = atoi(argv[2]);
    n2 = atoi(argv[3]);
    m2 = atoi(argv[4]);
    //FILE* arquivo1, arquivo2; 
    //std::cin>>arquivo1>>arquivo2;
   //cria matriz 1
    vector<vector<int>> matriz1;
    for (int i = 0; i < n1; i++){
        matriz1.push_back(vector<int>());
        for (int j = 0; j < m1; ++j) {
            matriz1[i].push_back(rand() % 10 + 1);
        }
    }

    //cria matriz 2
    vector<vector<int>> matriz2;
    for (int i = 0; i < n2; i++){
        matriz2.push_back(vector<int>());
        for (int j = 0; j < m2; ++j) {
            matriz2[i].push_back(rand() % 10 + 1);
        }
    }

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    //cria matriz resultado
    vector<vector<int>> res;
    for (int i = 0; i < n1; ++i) {
        res.push_back(vector<int>());
        for (int j = 0; j < m2; ++j) {
            res[i].push_back(0);
            for (int k = 0; k < m1; ++k) {
                res[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    chrono::steady_clock::time_point end = chrono::steady_clock::now();


    cout << "Tempo " <<chrono::duration_cast<chrono::microseconds>(end - begin).count() << "(ms)" <<endl;
    */
    arquivo1.close();
    //arquivo2.close();
}