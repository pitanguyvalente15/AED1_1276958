/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 02/11/2026
Objetivo    : Imprimir a sequência desejada
Dificuldade : 
Uso de IA   : Não usei
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int i = 1;
    int j = 60;

    while (j >= 0) {
        printf("I=%d J=%d\n", i, j);
        i += 3; 
        j -= 5; 
    }

    return 0;
}
