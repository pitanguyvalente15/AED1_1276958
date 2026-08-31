/* --------------------------------------------------------------------------
Disciplina : Algoritmos e Estruturas de Dados 2026S2
Nome : <<>>
Linguagem : C
Problema : https://judge.beecrowd.com/pt/problems/view/1383
Data : 24/08/2026
Objetivo : Escrever um programa que verifique se uma matriz preenchida é uma solução para o quebra-cabeça ou não.
Dificuldade : O principal desafio neste problema foi descobrir como verificar os 9 blocos do sudoku.
Uso de IA : Usei auxílio da IA para compreender como verificar os 9 blocos do sudoku.
-------------------------------------------------------------------------- */

#include <stdio.h>

// Verifica linhas, colunas e blocos de uma vez
int sudoku_valido(int sudoku[9][9]) {
    
    // 1. Verifica linhas e colunas
    for (int i = 0; i < 9; i++) {
        int linha_vista[10] = {0};
        int coluna_vista[10] = {0};
        
        for (int j = 0; j < 9; j++) {
            // Verifica a linha atual
            int val_linha = sudoku[i][j];
            if (val_linha < 1 || val_linha > 9 || linha_vista[val_linha]) return 0;
            linha_vista[val_linha] = 1;
            
            // Verifica a coluna atual
            int val_coluna = sudoku[j][i];
            if (val_coluna < 1 || val_coluna > 9 || coluna_vista[val_coluna]) return 0;
            coluna_vista[val_coluna] = 1;
        }
    }
    
    // 2. Verifica os blocos 3x3
    // r e c indicam o início de cada bloco
    for (int r = 0; r < 9; r += 3) {
        for (int c = 0; c < 9; c += 3) {
            
            int bloco_visto[10] = {0}; // Zera a contagem para cada bloco novo
            
            // Percorre os 9 elementos dentro do bloco atual
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int val = sudoku[r + i][c + j];
                    if (val < 1 || val > 9 || bloco_visto[val]) return 0;
                    bloco_visto[val] = 1; // Marca o numero como encontrado
                }
            }
            
        }
    }
    
    return 1; // Se passou por todos requisitos fica valido
}

int main() {
    int n;
    scanf("%d", &n); // Le a quantidade de instancias
    
    for (int k = 1; k <= n; k++) {
        int sudoku[9][9];
        
        // Lendo a matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        // Imprime o resultado
        printf("Instancia %d\n", k);
        if (sudoku_valido(sudoku) == 1) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    
    return 0;
}
