/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S2
Nome        : Clayton Pitanguy Valente
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 07/10/2026
Objetivo    : Imprimir uma mensagem informando se o termo entre parênteses está correto ou incorreto.
Dificuldade : Usar propriamente o case na função switch
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000

int bemFormada(char s[]);

int main(){
  //declarando a variável que recebe a expressão  
  char s[10000];
  //laço que recebe todas as expressões
    while(fgets(s, sizeof(s), stdin) != NULL){
        if(bemFormada(s)){
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
    }
    return 0;
}

int bemFormada(char s[]){
    //declarando as variáveis utilizadas dentro da função
    int t = 0, num, cont;
    num = strlen(s);
    //criando a pilha de parênteses
    char *p;
    p = malloc(num * sizeof(char));
    if(p == NULL){
        return 0;
    }
    for (cont = 0; s[cont] != '\0'; cont++) {
        switch (s[cont]) {
            case '(':
                p[t++] = '(';  //adiciona na pilha o parêntese de abertura
                break;

            case ')':
                //se a pilha não estiver vazia e o topo for '(', desempilha
                if (t > 0 && p[t - 1] == '(') {
                    t--; //
                } else {
                    free(p); //libera a memória antes de retornar
                    return 0; //retorna 0 porque existe um ')' sem um '(' prévio
                }
                break;

            default:
                //ignora qualquer coisa a não ser os parênteses
                break;
        }
    }    
    free(p);//libera a memória antes de retornar
    return t == 0; //retorna 1 para verdadeiro e 0 para falso

}
