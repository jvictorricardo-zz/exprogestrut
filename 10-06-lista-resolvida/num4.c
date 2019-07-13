#include<stdio.h>
#include<stdlib.h>

int main(){
    int **matriz;
    int linhas, colunas, i, j;
    
    printf("Digite quantas linhas deseja adicionar:  ");
    scanf("%d", &linhas);
    printf("Digite quantas colunas deseja adicionar:  ");
    scanf("%d", &colunas);
    
    matriz = (int **)malloc(sizeof(int)*linhas);
    for(i=0;i<linhas;i++){
        matriz[i] = (int *)calloc(colunas, sizeof(int));
    }
    
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("Digite um número:  ");
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(i=0;i<linhas;i++){
        printf("|");
        for(j=0;j<colunas;j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("|\n");
    }
    
    return 0;
}
