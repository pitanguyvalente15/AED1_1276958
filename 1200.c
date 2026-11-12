/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 12/11/2026
Objetivo    : Programa que seja possível utilizar as pincipais funções de uma árvore
Dificuldade : Evitar presentation error, retirar o espaço de antes ou depois da impressão dos itens da árvore.
Uso de IA   : A IA me deu a ideia de implementar o "primeiro" para resolver o problema dos espaços.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
    char valor;
    struct No *esq;
    struct No *dir;
}No;

No* criarNo(char x);
No *inserir(No *raiz, char valor);
void preOrdem(No *raiz, int *primeiro);
void emOrdem(No *raiz, int *primeiro);
void posOrdem(No *raiz, int *primeiro);
No *buscar(No *raiz, char valor);
void liberaArvore (No *raiz);

int main(){
    int primeiro = 1;
    No *raiz = NULL;
    char escolha[10];
    while(scanf("%9s", escolha) == 1){
        char add, proc;
        if(strcmp(escolha, "I") == 0){
            scanf(" %c", &add);
            raiz = inserir(raiz, add);
            
        }
        else if(strcmp(escolha, "P") == 0){
            scanf(" %c", &proc);
            No *resultado = buscar(raiz, proc);

            if(resultado != NULL) printf("%c existe", proc);
            else printf("%c nao existe", proc);
        }
        else if(strcmp(escolha, "PREFIXA") == 0) preOrdem(raiz, &primeiro);
        else if(strcmp(escolha, "INFIXA") == 0) emOrdem(raiz, &primeiro);
        else if(strcmp(escolha, "POSFIXA") == 0) posOrdem(raiz, &primeiro);
        else printf("Tem erro");
        if(strcmp(escolha, "I") != 0) printf("\n");
        primeiro = 1;
    }
    liberaArvore(raiz);
    return 0;
}

No *criarNo(char x){
    No* novo = malloc(sizeof(No));
    if(novo == NULL) return NULL;

    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, char valor){
    if(raiz == NULL)   return criarNo(valor);

    if(valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else if(valor > raiz->valor) raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void preOrdem(No *raiz, int *primeiro){
    if(raiz == NULL) return;

    if(*primeiro){
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
    else{
        printf(" %c", raiz->valor);
    }
    preOrdem(raiz->esq, primeiro);
    preOrdem(raiz->dir, primeiro);
}

void emOrdem(No *raiz, int *primeiro){
    if(raiz == NULL) return;

    emOrdem(raiz->esq, primeiro);
    if(*primeiro){
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
    else{
        printf(" %c", raiz->valor);
    }
    emOrdem(raiz->dir, primeiro);
}

void posOrdem(No *raiz, int *primeiro){
    if(raiz == NULL) return;

    posOrdem(raiz->esq, primeiro);
    posOrdem(raiz->dir, primeiro);
    if(*primeiro){
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
    else{
        printf(" %c", raiz->valor);
    }
}

No *buscar(No *raiz, char valor){
    if(raiz == NULL || raiz->valor == valor) return raiz;

    if(valor < raiz->valor) return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

void liberaArvore (No *raiz){
    if(raiz==NULL) return;

    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);

    free(raiz);
}
