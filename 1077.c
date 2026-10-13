/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 12/10/2026
Objetivo    : Converter infixa para posfixa
Dificuldade : Trabalhar propriamente com os operandos
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definicao do nó da Lista Encadeada para a Pilha
typedef struct Node {
    char data;
    struct Node *proximo;
} Node;

// Função para empilhar na lista encadeada
void push(Node **topo, char c) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (novoNo == NULL) return;
    
    novoNo->data = c;
    novoNo->proximo = *topo;
    *topo = novoNo;
}

// Função para desempilhar da lista encadeada
char pop(Node **topo) {
    if (*topo == NULL) return '\0';
    
    Node *temp = *topo;
    char valor = temp->data;
    *topo = (*topo)->proximo;
    free(temp);
    
    return valor;
}

// Função para verivicar o topo da pilha sem remover
char verif(Node *topo) {
    if (topo == NULL) return '\0';
    return topo->data;
}

// Função para verificar se a pilha esta vazia
int estaVazia(Node *topo) {
    return topo == NULL;
}

// Função para definir a precedencia dos operadores conforme a matematica indica
int precedencia(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0; // '(' possui prioridade 0 dentro da pilha
    }
}

// Função principal de conversao Infixa para Posfixa
void converteInfixaParaPosfixa(char *infixa) {
    Node *pilha = NULL;
    int i = 0;

    while (infixa[i] != '\0' && infixa[i] != '\n' && infixa[i] != '\r') {
        char c = infixa[i];

        // 1. Se for operando (letra ou numero), imprime diretamente
        if (isalnum(c)) {
            printf("%c", c);
        }
        // 2. Se for '(', empilha
        else if (c == '(') {
            push(&pilha, c);
        }
        // 3. Se for ')', desempilha ate encontrar '('
        else if (c == ')') {
            while (!estaVazia(pilha) && verif(pilha) != '(') {
                printf("%c", pop(&pilha));
            }
            if (!estaVazia(pilha) && verif(pilha) == '(') {
                pop(&pilha); // Remove o '(' da pilha
            }
        }
        // 4. Se for operador (+, -, *, /, ^)
        else {
            while (!estaVazia(pilha) && precedencia(verif(pilha)) >= precedencia(c)) {
                printf("%c", pop(&pilha));
            }
            push(&pilha, c);
        }
        i++;
    }

    // Desempilha todos os operadores restantes
    while (!estaVazia(pilha)) {
        printf("%c", pop(&pilha));
    }
    printf("\n");
}

int main() {
    int N;
    char infixa[300];

    if (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            scanf("%s", infixa);
            converteInfixaParaPosfixa(infixa);
        }
    }

    return 0;
}
