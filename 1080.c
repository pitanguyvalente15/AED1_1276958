/* --------------------------------------------------------------------------
Disciplina : Algoritmos e Estruturas de Dados 2026S2
Nome : <<>>
Linguagem : C
Problema : https://judge.beecrowd.com/pt/problems/view/1080
Data : 24/08/2026
Objetivo : Leia 100 números inteiros. Imprima o maior valor lido e a posição de entrada.
Dificuldade : O principal desafio neste problema foi calcular a posição exata do maior número, já que decidi guardar os 100 valores em uma matriz.
Uso de IA : Não usei IA.
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
    int vet[10][10];
    int maior, pos;
    //lendo 100 numeros inteiros
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            scanf("%d", &vet[i][j]);
        }
    }
    //procurando o maior numero
    maior = vet[0][0];
    pos = 1;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(vet[i][j]>maior){
                maior = vet[i][j];
                pos = (i*10)+j+1;
            }
        }
    }
    //imprimindo o maior numero e sua posicao
    printf("%d\n", maior);
    printf("%d\n", pos);
    
    return 0;
}
