#include<stdio.h>
#include<stdlib.h>

int main(){
    int mat[2][2];
    int i,j;
    float media=0;
    
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("Digite um número:  ");
            scanf("%d", &mat[i][j]);
            media+=mat[i][j];
        }
    }
    
    media = media/20.0;
    
    for(i=0;i<2;i++){
        printf("|");
        for(j=0;j<2;j++){
            if(mat[i][j]<media) printf(" ** ");
            else printf(" %02d ", mat[i][j]);
        }
        printf("|\n");
    }
    

    return 0;
}
