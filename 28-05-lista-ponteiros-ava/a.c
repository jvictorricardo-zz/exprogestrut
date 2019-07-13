#include<stdio.h>
#include<stdlib.h>

int menor(int *vetor, int menorv, int i);

int main(){
    int vetor[100];
    int i=0;
    
    for(i=0;i<100;i++){//preenche
        vetor[i]=i;
    }
    
    vetor[76] = -1;
    
    i = menor(vetor, 0, 0);
    
    printf("menor:  %d\n", i);
    
    return 0;
}



int menor(int *vetor, int menorv, int i){
    if (i>99){ //acabou
        return menorv;
    }
    else{
        if (i==0){
            menorv = vetor[0];
        }
        if(vetor[i]<menorv){
            menorv=vetor[i];
        }
        return menor(vetor, menorv, i+=1);
    }
}
