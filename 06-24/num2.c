#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    int i=0;
    char nome[50], linha[1000];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);
    fp = fopen(nome, "r");
    while(!feof(fp)){
        fgets(linha, 1000, fp);
        printf("%s", linha);
        i++;
    }
    printf("Quantidade de linhas: %d\n", i);
    return 0;
}
