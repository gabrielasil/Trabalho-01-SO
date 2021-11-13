//crie um programa que leia duas matrizes de dois arquivos e multiplique as duas matrizes usando threads
#include<iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

//subrotina que multiplica duas matrizes


vector<vector<int>> matriz1;
vector<vector<int>> matriz2;
vector<vector<int>> matriz3;
int mat_size = 0;
int P = 0;
int linha_atual = 0;
int coluna_atual = 0;

void* multi(void* tid)
{
	int linha_atual = (P * (size_t)tid) / mat_size;
	int coluna_atual = (P * (size_t)tid )% mat_size;

	for(int i = 0; i < P; i++){
		for(int j = 0; j < mat_size; j++){
			matriz3[linha_atual][coluna_atual] += matriz1[linha_atual][j] * matriz2[j][coluna_atual];
		}
		coluna_atual++;
		if(coluna_atual == mat_size){				
			linha_atual++;
			coluna_atual = 0;
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	string arq1, arq2, linha;
    char num;
    arq1 = argv[1];
    int l1{0}, c1{0}, l2{0}, c2{0}, n, pos{0};
    arq2 = argv[2];
	P = atoi(argv[3]);
    fstream arquivo1;
    fstream arquivo2;
    //fstream arquivo3;
    //abre o arquivo 1
    arquivo1.open(arq1, ios::in); 

    if (!arquivo1) {
		cout << "No such file";
	}

    //le o arquivo 1
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
	//cout << matriz1.size()<<endl;
	mat_size = matriz1.size()-1;
	int MAX_THREADS = (mat_size * mat_size) / P;
	//cout << MAX_THREADS << endl;

	for(int i = 0; i < mat_size; i++){
		matriz3.push_back(vector<int>());
		for(int j = 0; j < mat_size; j++){
			matriz3[i].push_back(0);
		}
	}

    pthread_t threads[MAX_THREADS];
 

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, multi, (void*)(size_t)(i));
    }


    for (int i = 0; i < MAX_THREADS; i++){
		pthread_join(threads[i], NULL);
	}  

    cout << endl;
    for (int i = 0; i < mat_size; i++) {
        for (int j = 0; j < mat_size; j++)
            cout << matriz3[i][j] << " ";       
        cout << endl;
    }
    return 0;
}


