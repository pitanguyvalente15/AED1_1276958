/* --------------------------------------------------------------------------
Disciplina : Algoritmos e Estruturas de Dados 2026S2
Nome : Clayton Pitanguy Valente
Linguagem : C
Problema : https://judge.beecrowd.com/pt/problems/view/1080
Data : 27/08/2026
Objetivo : Leia 100 números inteiros. Imprima o maior valor lido e a posição de entrada. Use alocação dinâmica
Dificuldade : Compreender a sintaxe da função malloc
Uso de IA : Não usei
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int maior, pos;
    int *vetor;

    //alocação dinâmica do vetor
    vetor = (int *) malloc(100 * sizeof(int));
    if(vetor == NULL){
        printf("Erro: Posicoes em excesso");
        return 1;
    }

    //preenchendo o vetor
    for(int i = 0; i<100; i++){
        vetor[i] = i*i;
    }

    //determinando o maior numero e sua posicao
    maior = vetor[0];
    pos = 0;

    //achando o maior numero e sua posicao
    for(int i = 0; i<100; i++){
        if(vetor[i]>maior){
            maior = vetor[i];
            pos = i;
        }
    }

    //imprimindo os resultados;
    printf("%d\n", maior);
    printf("%d\n", pos);

    //Liberando espaço de memória
    free(vetor);
    
    return 0;
}
