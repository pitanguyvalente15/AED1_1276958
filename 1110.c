/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 30/09/2026
Objetivo    : Encontrar a sequência de cartas descartadas e a última carta restante.
Dificuldade : Criar as funções "enfileirar" e "desenfileirar"
Uso de IA   : Usei IA para compreender como funcionam as funções "enfileirar" e "desenfileirar" em uma fila
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

// Função para inserir uma carta no final da fila
void enfileirar(Node **inicio, Node **fim, int val) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->valor = val;
    novo->prox = NULL;
    
    if (*fim == NULL) { // Caso fila vazia
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }
}

// Função para remover uma carta do início da fila
int desenfileirar(Node **inicio, Node **fim) {
    if (*inicio == NULL) return -1;
    
    Node *temp = *inicio;
    int val = temp->valor;
    *inicio = (*inicio)->prox;
    
    if (*inicio == NULL) { // Caso a fila tenha ficado vazia
        *fim = NULL;
    }
    
    free(temp);
    return val;
}

int main() {
    int n;
    
    // Lê n até encontrar o número 0
    while (scanf("%d", &n) == 1 && n != 0) {
        Node *inicio = NULL;
        Node *fim = NULL;
        
        // Preenchendo a fila com as cartas de 1 até n
        for (int i = 1; i <= n; i++) {
            enfileirar(&inicio, &fim, i);
        }
        
        int descartadas[50];
        int qtd_descartadas = 0;
        
        //  Processa enquanto houver pelo menos duas cartas
        while (inicio != NULL && inicio != fim) {
            // Descarta a carta do topo
            descartadas[qtd_descartadas++] = desenfileirar(&inicio, &fim);
            
            // Move a próxima carta do topo para o fim da fila
            int carta_topo = desenfileirar(&inicio, &fim);
            enfileirar(&inicio, &fim, carta_topo);
        }
        
        // Impressão das cartas descartadas (Atenção aos espaços e vírgulas)
        printf("Discarded cards:");
        for (int i = 0; i < qtd_descartadas; i++) {
            if (i == 0) {
                printf(" %d", descartadas[i]);
            } else {
                printf(", %d", descartadas[i]);
            }
        }
        printf("\n");
        
        // Impressão da carta restante
        if (inicio != NULL) {
            printf("Remaining card: %d\n", inicio->valor);
            free(inicio); // Libera a memória da última carta, um malloc e um free
        }
    }
    
    return 0;
}
