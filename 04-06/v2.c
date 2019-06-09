#include<stdio.h>
#include<stdlib.h>

int *criaVetor(int numItens);
void impressao(int *vetor, int qtdItens);

int main(){
    int *v;
    int n, i;
    
    printf("Digite n:  ");
    scanf("%d", &n);
    
    v = criaVetor(n);    
    impressao(v, n);
    
    return 0;
}


int *criaVetor(int numItens){//cria e preenche
    int i;
    int *vetor;
    vetor = (int *) malloc(numItens * sizeof(int));
    for(i=0;i<numItens;i++){
        printf("Digita aí meu parça:  ");
        scanf("%d", &vetor[i]);
    }
    return vetor;
}

//recebe um ponteiro int * e um valor de n e imprime os valores
void impressao(int *vetor, int qtdItens){
    int i;
    for(i=0;i<qtdItens;i++){
        printf("V[%d] = %d\n", i, vetor[i]);        
    }
}
