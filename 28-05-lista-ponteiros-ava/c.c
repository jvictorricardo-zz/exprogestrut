#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int quantcasas(int num);
long int somadigitos(long int num);


int main(){
    printf("quant casas: %d\n", quantcasas(2023));
    printf("soma dos digitos: %ld\n", somadigitos((long int)2023));
    return 0;
}

int quantcasas(int num){
    int quant=1;
    while((num = num/10)>0){
        quant++;
    }
    return quant;
}

long int somadigitos(long int num){
    int casas=0;
    long int soma=0;
    
    casas = quantcasas(num);
    while(casas>0){
        soma += (num%(int)pow(10,casas)/(int)(pow(10,casas-1)));
        casas--;
    }
    return soma;
}
