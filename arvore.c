#include <stdio.h>
#include <stdlib.h>

//Esse programa contem as principais funções de uma árvore, dependendo da atividade será necessário realizar modificações, use essas funções para dar um norte

//função que define a estrutura de uma árvore
typedef struct{
    int valor;
    struct No *esq;
    struct No *dir;
}No;

//função que cria um novo nó na árvore 
No* criarNo(int x){
    No* novo = malloc(sizeof(No));
    if(novo == NULL) return;

    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//função que insere um valor na árvore
No *inserir(No *raiz, int valor){
    if(raiz == NULL)   return criarNo(valor);

    if(valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else if(valor > raiz->valor) raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

//função que busca um valor na árvore
No *buscar(No *raiz, int valor){
    if(raiz == NULL || raiz->valor == valor) return raiz;

    if(valor < raiz->valor) return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

/*
        8
    4       12
2       6       
*/

//função que percorre a árvore na pré-ordem, a raiz é processada antes dos filhos
// 8 4 2 6 12
void preOrdem(No *raiz){
    if(raiz == NULL) return;

    printf("%d", raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

//função que percorre a árvore em ordem (o percurso em ordem imprime os valores em ordem crescente, desde que os valores repetidos não sejam armazenados)
// 2 4 6 8 12
void emOrdem(No *raiz){
    if(raiz == NULL) return;

    emOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    emOrdem(raiz->dir);
}

//função que percorre a árvore na pós-ordem, a raiz é processada depois dos filhos
// 2 6 4 12 8
void posOrdem(No *raiz){
    if(raiz == NULL) return;

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d ", raiz->valor);
}

//função que conta quantos nós a árvore tem
int contarNos(No *raiz){
    if(raiz == NULL) return 0;

    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

//função que conta quantas folhas existem (folhas sãos os nós que não possuem filhos, ou seja, a direita e esquerda são NULL)
// 3 (2, 6, 12)
int contarFolhas(No *raiz){
    if(raiz == NULL) return 0;

    if(raiz->esq == NULL && raiz->dir == NULL) return 1;

    return 1 + contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

//função que calcula a altura da árvore 
int altura(No *raiz){
    if(raiz == NULL) return 0;

    int hEsq = altura(raiz->esq);
    int hDir = altura(raiz->dir);

    if(hEsq > hDir) return hEsq+1;
    
    return hDir+1;
}

//função que encontra o menor valor da árvore (retorna o ponteiro para o nó, não diretamente o inteiro)
No *menorNo(No *raiz){
    if(raiz == NULL) return 0;

    while(raiz->esq != NULL) raiz = raiz->esq;

    return raiz;
}

//função que encontra o maior valor da árvore (retorna o ponteiro para o nó, não diretamente o inteiro)
No *maiorNo(No *raiz){
    if(raiz == NULL) return 0;

    while(raiz->dir != NULL) raiz = raiz->dir;

    return raiz;
} 

//função que remove um nó de uma árvore, considerando que os valores não re repetem
No *remover(No *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        // Caso 1 e 2: nenhum filho ou apenas um filho
        if (raiz->esq == NULL) {
            No *temp = raiz->dir;
            free(raiz);
            return temp;
        }

        if (raiz->dir == NULL) {
            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 3: dois filhos
        No *sucessor = menorNo(raiz->dir);

        raiz->valor = sucessor->valor;

        raiz->dir = remover(raiz->dir, sucessor->valor);
    }

    return raiz;
}

//função que limpa a memória alocada pela árvore
void liberaArvore (No *raiz){
    if(raiz==NULL) return;

    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);

    free(raiz);
}

//função principal
int main(){
    int x;
    scanf("%d", &x);
    criarNo(x);
    No *raiz = NULL;

    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 6);
    return;

    No *resultado = buscar(raiz, 6);

    if(resultado != NULL) printf("Valor encontrado %d \n", resultado->valor);
    else printf("Valor nao encontrado\n");
}
