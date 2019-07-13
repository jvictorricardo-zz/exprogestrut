#include<stdio.h>
#include<stdlib.h>

void contrario(int *vetor, int comeco, int fim);


int main(){
    int vetor[30];
    int i=0;
    
    for(i=0;i<30;i++){
        vetor[i]=i;
    }

    contrario(vetor, 1, 30);
    printf("\n");



    return 0;
}

void contrario(int *vetor, int comeco, int fim){
    if(comeco<fim){
        printf(" %d ", vetor[fim-comeco]);
        return contrario(vetor, comeco+=1, fim);
    }    
}
