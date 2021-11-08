#include<iostream>
using std::cout;
using std::endl;
#include <chrono>
#include <vector>
#include <fstream>
using std::ofstream;
#include <cstdlib>
//#include "auxiliar.h"
//#include "function.h"
//abrir o arquivo
//outfile.open("caminho do arquivo", std::ios_base::app); 

//escrever no arquivo
//outfile<<pos<<"          ";

//fechar o arquivo
//outfile.close();

//usar o chrono
//auto start = std::chrono::steady_clock::now();/*comeca a contagem do tempo*/
//std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();//auto result = sa::bsearch( &vet[0], &vet[pos], valor );
//std::chrono::duration<double> diff = end - start;
// Milliseconds (10^-3)
//std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()<< " ms" << std::endl;
//soma+=std::chrono::duration <double, std::milli> (diff).count();


//cria vetor de coluna
//preenche a coluna1 com os enderecos dos vetores de linha

void auxiliar(int l1, int c1, int l2, int c2){
    std::ofstream outfile;
    outfile.open("/root/Fernanda/TI-2021.2/SO/trabalho-01/Trabalho-01-SO/matriz1", std::ios_base::app); 
    std::vector<std::vector<int>>coluna1;/*cria o vetor da coluna1*/
    for(int i{0}; i<l1; i++){/*cria as l1 posicoes pra os vetores de linha*/
        coluna1.push_back(std::vector<int>());/*cria vetor dentro da posicao*/
        for(int j{0}; j<c1; j++){/*preenche o vetor da linha*/
            coluna1[i].push_back(rand()%10+1);/*gera um valor aleatorio*/
            outfile<<coluna1[i][j]<<" ";
        }
        outfile<<endl;
    }
    outfile.close();

    outfile.open("/root/Fernanda/TI-2021.2/SO/trabalho-01/Trabalho-01-SO/matriz2", std::ios_base::app); 
    std::vector<std::vector<int>>coluna2;
    for(int i{0}; i<l2; i++){
        coluna2.push_back(std::vector<int>());
        for(int j{0}; j<c2; j++){
            coluna2[i].push_back(rand()%10+1);
            outfile<<coluna2[i][j]<<" ";
        }
        outfile<<endl;
    }
    outfile<<endl;
    outfile.close();
}


int main(){
    int l1, c1, l2, c2;
    std::cin>>l1>>c1>>l2>>c2;
    auxiliar(l1, c1, l2, c2);
    return 0;
}

