/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 12/11/2026
Objetivo    : O usuário preenche quanas árvores ele desejar e o programa imprime a árvore em preordem, emordem e posordem.
Dificuldade : Evitar presentation error, retirar o espaço de antes ou depois da impressão dos itens da árvore.
Uso de IA   : Não usei.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
}No;

No *criarNo(int x);
No *inserir(No *raiz, int valor);
void preOrdem(No *raiz, int *primeiro);
void emOrdem(No *raiz, int *primeiro);
void posOrdem(No *raiz, int *primeiro);
void liberaArvore(No *raiz);

int main(){
    int C, N, add;

    scanf("%d", &C);

    for(int i = 0; i<C; i++){
        int primeiro = 1;
        No *raiz = NULL;

        scanf("%d", &N);

        for(int j = 0; j<N; j++){
            scanf("%d", &add);
            raiz = inserir(raiz, add);            
        }
        
        printf("Case %d:", i+1);
        printf("\nPre.: ");

        preOrdem(raiz, &primeiro);
        primeiro = 1;

        printf("\nIn..: ");
        emOrdem(raiz, &primeiro);
        primeiro = 1;

        printf("\nPost: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n");

        liberaArvore(raiz);
        raiz = NULL;
    }
    return 0;
}

No *criarNo(int x){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return NULL;

    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, int valor){
    if(raiz == NULL) return criarNo(valor);

    if(valor<raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else if(valor>raiz->valor) raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void preOrdem(No *raiz, int *primeiro){
    if(raiz == NULL) return;

    if(*primeiro){
        printf("%d", raiz->valor);
        *primeiro = 0;
    }
    else{
        printf(" %d", raiz->valor);
    }
    preOrdem(raiz->esq, primeiro);
    preOrdem(raiz->dir, primeiro);
}

void emOrdem(No *raiz, int *primeiro){
    if(raiz == NULL) return;

    emOrdem(raiz->esq, primeiro);
    if(*primeiro){
        printf("%d", raiz->valor);
        *primeiro = 0;
    }
    else{
        printf(" %d", raiz->valor);
    }
    emOrdem(raiz->dir, primeiro);
}

void posOrdem(No *raiz, int *primeiro){
    if(raiz == NULL) return;

    posOrdem(raiz->esq, primeiro);
    posOrdem(raiz->dir, primeiro);
    if(*primeiro){
        printf("%d", raiz->valor);
        *primeiro = 0;
    }
    else{
        printf(" %d", raiz->valor);
    }
}

void liberaArvore (No *raiz){
    if(raiz==NULL) return;

    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);

    free(raiz);
}
