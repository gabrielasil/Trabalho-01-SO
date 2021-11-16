#include<iostream>
using std::cout;
using std::endl;
#include <chrono>
#include <vector>
#include <fstream>
using std::ofstream;
#include <cstdlib>


int main(int argc, char *argv[]){
    int l1,c1,l2,c2;
    l1 = atoi(argv[1]);
    c1 = atoi(argv[2]);
    l2 = atoi(argv[3]);
    c2 = atoi(argv[4]);

    std::ofstream outfile;
    outfile.open("matriz1", std::ios_base::app); 
    std::vector<std::vector<int>>coluna1;/*cria o vetor da coluna1*/
    for(int i{0}; i<l1; i++){/*cria as l1 posicoes pra os vetores de linha*/
        coluna1.push_back(std::vector<int>());/*cria vetor dentro da posicao*/
        for(int j{0}; j<c1; j++){/*preenche o vetor da linha*/
            coluna1[i].push_back(rand()%10);/*gera um valor aleatorio*/
            outfile<<coluna1[i][j]<<" ";
        }
        outfile<<endl;
    }
    outfile.close();

    outfile.open("matriz2", std::ios_base::app); 
    std::vector<std::vector<int>>coluna2;
    for(int i{0}; i<l2; i++){
        coluna2.push_back(std::vector<int>());
        for(int j{0}; j<c2; j++){
            coluna2[i].push_back(rand()%10);
            outfile<<coluna2[i][j]<<" ";
        }
        outfile<<endl;
    }
    outfile<<endl;
    outfile.close();
    return 0;
}

