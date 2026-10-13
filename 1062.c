/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 13/10/2026
Objetivo    : Escrever um programa que determine se é possível obter a ordem de vagões desejada usando pilha
Dificuldade : Compreender como funciona a entrada descrita pelo beecrowd no código
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1005

// Estrutura da Pilha estática
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, int valor) {
    p->topo++;
    p->dados[p->topo] = valor;
}

void pop(Pilha *p) {
    if (p->topo >= 0) {
        p->topo--;
    }
}

int top(Pilha *p) {
    return p->dados[p->topo];
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int main() {
    int N;

    // Processa até encontrar N = 0
    while (scanf("%d", &N) == 1 && N != 0) {
        while (1) {
            int alvo[MAX];
            
            // Lê o primeiro vagão
            scanf("%d", &alvo[0]);

            // Se for 0, encerra a leitura dos vagões para este N
            if (alvo[0] == 0) {
                break;
            }

            // Lê o restante dos vagões
            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            Pilha estacao;
            inicializar(&estacao);

            int indiceAlvo = 0;

            // Chegada sequencial dos vagões de 1 a N vindos do trilho A
            for (int vagon = 1; vagon <= N; vagon++) {
                push(&estacao, vagon);

                // Desempilha enquanto o topo corresponder ao vagão exigido no trilho B
                while (!estaVazia(&estacao) && top(&estacao) == alvo[indiceAlvo]) {
                    pop(&estacao);
                    indiceAlvo++;
                }
            }

            // Se todos os N vagões saíram na ordem correta
            if (indiceAlvo == N) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        // Evitar erro do beecrowd
        printf("\n");
    }

    return 0;
}
