#include <stdio.h>
 
int main() {
    int vet[10][10];
    int maior, pos;
    //lendo 100 numeros inteiros
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            scanf("%d", &vet[i][j]);
        }
    }
    //procurando o maior numero
    maior = vet[0][0];
    pos = 1;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(vet[i][j]>maior){
                maior = vet[i][j];
                pos = (i*10)+j+1;
            }
        }
    }
    //imprimindo o maior numero e sua posicao
    printf("%d\n", maior);
    printf("%d\n", pos);
    
    return 0;
}
