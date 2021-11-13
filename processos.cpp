//recebe como entrada dois arquivos e um numero inteiro p (particao)
//dividir a matriz em p elementos, e dar cada particao para um processo diferente
//lembrar de abrir e fechar o arquivo antes de criar qualquer processo
//criar tam*tam/p arquivos, cada um recebe apenas uma parte do resultado
//cada arquivo comeca com o tamanho da matriz total (tam)

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
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    string arq1, arq2, linha;
    char num;
    int p;
    arq1 = argv[1];
    int l1{0}, c1{0}, l2{0}, c2{0}, n, pos{0};
    arq2 = argv[2];
    p = atoi(argv[3]);
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

    //le o arquivo 2
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

    arquivo1.close();
    arquivo2.close();


    //criacao da matriz resultado
    vector<vector<int>> res;
    size_t tam{matriz1.size()-1};
    int nprocessos = tam*tam/p;
    int pid;
    int inicial{0}, final{0}, x{0}, y{0};
    //std::cout<<"tam: "<<tam<<endl;
    //inicia a criacao de processos
    for(int i{0}; i<nprocessos; i++){
        //onde o processo deve comecar e terminar de calcular na matriz
        inicial = p*i;
        final = p*(i+1);
        //std::cout<<"processo "<<i<<endl;
        //pai cria o filho dentro do for
        pid = fork();
        //filhos so executam dentro do if
        if(pid==0){
            //std::cout<<"sou o processo "<<i<<" vou calcular de "<<inicial<<" até antes de "<<final<<endl;
            //k é o contador da posicao linear da matriz em que o processo esta calculando
            for(int k{inicial}; k<final; k++){
                std::cout<<i<<" k: "<<k<<endl;
                //calculo da posicao em 2d na matriz
                x = k/tam;
                y = k%tam;
                //checa se esta na coluna 0
                if(y==0){
                    //std::cout<<endl;
                    //aumenta em uma linha
                    std::cout<<i<<" aumentando em uma linha\n";
                    res.push_back(vector<int>());
                }
                //aumenta em uma posicao da linha
                //dando erro na hora de aumentar a posicao do vetor, na posicao 10
                res[x].push_back(0);
                //calcular o elementos x y da matriz dentro do intervalo do processo
                for(int a{0}; a<tam; a++){
                    std::cout<<i<<" k: "<<k<<" tam: "<<tam<<" "<<x<<a<<" * "<<a<<y<<endl;
                    //erro ao tentar imprimir res[x][y] na posicao 10
                    res[x][y] += matriz1[x][a] * matriz2[a][y];
                    //std::cout<<i<<" k: "<<k<<" tam: "<<tam<<" "<<x<<a<<" * "<<a<<y<<endl;
                }
                
                std::cout<<i<<" "<<x<<y<<": "<<res[x][y]<<" \n";
                
            }
            //o break faz com que os filhos terminem de executar depois do calculo e nao criem mais filhos
            break;
        }
    }

    return 0;
}