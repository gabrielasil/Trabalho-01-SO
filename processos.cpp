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
#include <bits/stdc++.h>
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
    for(size_t d{0}; d<tam; d++){
        res.push_back(vector<int>());
        for(size_t c{0}; c<tam; c++){
            res[d].push_back(0);
        }
    }

    int nprocessos = tam*tam/p;
    int vetor_pid[nprocessos];
    //int pid;
    int inicial{0}, final{0}, x{0}, y{0};

    //inicia a criacao de processos
    for(int i{0}; i<nprocessos; i++){ 
        //onde o processo deve comecar e terminar de calcular na matriz
        inicial = p*i;
        final = p*(i+1);
        //pai cria o filho dentro do for
        vetor_pid[i] = fork();
        //filhos so executam dentro do if
        if(vetor_pid[i]==0){
            //cria o arquivo dentro do processo filho
            stringstream arch;
            arch<<"processo_"<<i<<".txt";
            ofstream file;
            file.open(arch.str());
            //inicia a marcacao do tempo
            file<<tam<<" x "<<tam<<endl;
            chrono::steady_clock::time_point begin = chrono::steady_clock::now();
            //k é o contador da posicao linear da matriz em que o processo esta calculando
            for(int k{inicial}; k<final; k++){
                //calculo da posicao em 2d na matriz
                x = k/tam;
                y = k%tam;
                //calcular o elementos x y da matriz dentro do intervalo do processo
                for(size_t a{0}; a<tam; a++){
                    res[x][y] += matriz1[x][a] * matriz2[a][y];
                }
                file<<"c"<<x<<y<<" "<<res[x][y]<<endl;
            }
            //finaliza a marcacao do tempo
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            file<<"Tempo: "<<chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "(ms)" <<endl;
            
            file.close();
            cout <<i<< " Tempo " <<chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "(ms)" <<endl;
            //o break faz com que os filhos terminem de executar depois do calculo e nao criem mais filhos
            break;
        }
    }

    return 0;
}