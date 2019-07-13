#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, N, M, k, iguais=0;
    int A[100], B[100];
    
    printf("Digite a qtd de elementos de A: ");
    scanf("%d", &N);
    while(N<0 ||N>100){
        printf("Qtd inválida, digite novamente: ");
        scanf("%d", &N);
    }
    
    printf("Digite a qtd de elementos de B: ");
    scanf("%d", &M);
    while(M<0 ||M>100){
        printf("Qtd inválida, digite novamente: ");
        scanf("%d", &M);
    }
    
    printf("\n%d\n%d\n", N, M);
    
    //entrada de elementos
    printf("Digite os elementos de A\n");
    for(i=0;i<N;i++){
        printf("Digite um elemento:  ");
        scanf("%d", &A[i]);
    }
    
    //entrada de elementos
    printf("Digite os elementos de B\n");
    for(i=0;i<M;i++){
        printf("Digite um elemento:  ");
        scanf("%d", &B[i]);
    }
    
    //verificando repetidos
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(A[i]==A[j]){
                for(k=j;k<N;k++){
                    A[k] = A[k+1];
                }
                N--;
            }
        }
    }
    
    //verificando repetidos
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            if(B[i]==B[j]){
                for(k=j;k<M;k++){
                    B[k] = B[k+1];
                }
                M--;
            }
        }
    }
    
    //verifica a continência
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(A[i]==B[j]){
                iguais++;
                if(N==M==1) break;
            }
        }
    }
    

    if(iguais==N) printf("A está contido em B\n");
    else printf("A NÃO ESTÁ contido em B\n");
    
    printf("%d", iguais);
    
    return 0;
}
