#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, s, n, acertos=0;
    int *elementos, *sorteados;
    
    printf("Digite quantos elementos você marcou:  ");
    scanf("%d", &n);
    elementos = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Digite o %dº número marcado:  ", i+1);
        scanf("%d", &elementos[i]);
    }
    
    printf("Digite quantos elementos foram sorteados:  ");
    scanf("%d", &s);
    sorteados = (int *)malloc(sizeof(int)*s);
    for(i=0;i<s;i++){
        printf("Digite o %dº número sorteado:  ", i+1);
        scanf("%d", &sorteados[i]);
    }
    
    for(i=0;i<s;i++){
        for(j=0;j<n;j++){
            if(sorteados[i]==elementos[j]){
                acertos++;
            }
        }
    }
    
    printf("\nVocê acertou %d número(s)\n\n", acertos);
    
    return 0;
}
