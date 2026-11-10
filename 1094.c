/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : 10/11/2026
Objetivo    : Ler quantidade de animais dos experimentos e imprimir os números desejadas.
Dificuldade : colocar o espaço antes do %c na leitura do esp
Uso de IA   : Não usei
-------------------------------------------------------------------------- */
#include <stdio.h>

int main(){
    int N = 0, qC = 0, qR = 0, qS = 0, temp = 0, total = 0;  
    char esp;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        scanf(" %c", &esp);
        total = temp + total;

        if(esp == 'S')
            qS = qS+temp;
        
        else if(esp == 'R')
            qR = qR+temp;

        else
            qC = qC+temp;
    }

    float pC = ((float)qC/total)*100;
    float pR = ((float)qR/total)*100;
    float pS = ((float)qS/total)*100;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", qC);
    printf("Total de ratos: %d\n", qR);
    printf("Total de sapos: %d\n", qS);
    printf("Percentual de coelhos: %.2f %\n", pC);
    printf("Percentual de ratos: %.2f %\n", pR);
    printf("Percentual de sapos: %.2f %\n", pS);

    return 0;
}
