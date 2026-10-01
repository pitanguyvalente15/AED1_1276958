/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 01/10/2026
Objetivo    : Achar o tempo gasto.
Dificuldade : Entender os erros que o beecrowd
Uso de IA   : Sim, para interpretar os erros do beecrowd
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>


void preencheVetor(int *vet,int num);
int buscaBinaria(int numcasas[], int N,int valor);

int main(){
    //declarando variaveis
    int Tempo, N, M, posicaoAtual = 0, posicaoDestino = 0;
    int *numcasas;
    int *numpedidos;
    long long tempoGasto = 0;

    
    scanf("%d %d", &N, &M);
    numcasas = (int*) malloc(N*sizeof(int));
    numpedidos = (int*) malloc(M*sizeof(int));
    
    preencheVetor(numcasas, N);
    preencheVetor(numpedidos, M);

    for(int i = 0; i<M; i++){
        posicaoDestino = buscaBinaria(numcasas, N, numpedidos[i]);
        tempoGasto += abs(posicaoDestino - posicaoAtual);
        posicaoAtual = posicaoDestino;
    }

    printf("%lld\n", tempoGasto);

    free(numcasas);
    free(numpedidos);

    return 0;
}

void preencheVetor(int *vet,int num){
    for(int i = 0; i<num; i++)
        scanf("%d", vet+i);
}

int buscaBinaria(int numcasas[], int N,int valor){
    int esquerda = 0;
    int direita = N-1;
    int meio;

    while(esquerda<=direita){
        meio = (esquerda+direita)/2;
   
        if(valor == numcasas[meio]){
            return meio;
        }

        if(numcasas[meio]<valor){
            esquerda = meio+1;
        }
        else{
            direita = meio -1;
        }

    }

   return -1;
} 
