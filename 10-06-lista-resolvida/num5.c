#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char codigo[50];
    int quant;
    float  preco;
}produto;



int main(){
    produto *estoque;
    int numEstoque, i, indMaior, indMais;
    
    printf("Digite quantos produtos deseja cadastrar:  ");
    scanf("%d", &numEstoque);
    fflush(stdin);
    estoque = (produto *)malloc(sizeof(produto)*numEstoque);
    
    for(i=0;i<numEstoque; i++){
        printf("Digite o código do produto:  ");
        //fgets(estoque[i].codigo, 50, stdin)/;
        scanf("%s",estoque[i].codigo); 
        fflush(stdin);
        printf("Digite a quantidade do produto:  ");
        scanf("%d", &estoque[i].quant);
        fflush(stdin);
        printf("Digite o preço do produto:  ");
        scanf("%f", &estoque[i].preco);
        fflush(stdin);
    }

    for(i=1;i<numEstoque; i++){
        if(estoque[i].preco>estoque[i-1].preco){
            indMaior = i;
        }
        if(estoque[i].quant>estoque[i-1].quant){
            indMais = i;
        }
    }
    
    printf("Produto mais caro\ncódigo: %s\npreço: %02.2f\n\n", estoque[indMaior].codigo, estoque[indMaior].preco);
    printf("Produto em maior quant.\ncódigo: %s\nquantidade: %02d\n\n", estoque[indMais].codigo, estoque[indMais].quant);
    
    return 0;
}
