#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int tam, i;
    char *entrada;
    
    printf("Digite o tamanho da string:  ");
    scanf("%d", &tam);
    fflush(stdin);
    while(tam<0){
        printf("Digite novamente o tamanho da string:  ");
        scanf("%d", &tam);
        fflush(stdin);
    }
    
    getchar();
    
    entrada = (char *)calloc(tam, sizeof(char));

    printf("Digite sua frase: ");
    for(i=0;i<tam;i++){
        scanf("%c", &entrada[i]);
        if(entrada[i]=='\n'){
            break;
        }
    }
    entrada[i]='\0';
    
    
    printf("Frase digitada:  ");
    for(i=0;i<tam;i++){
        printf("%c", entrada[i]);
    }
    printf("\n");
    
    printf("Frase sem as vogais: ");
    for(i=0;i<tam;i++){
        if(entrada[i]!='A'&&
            entrada[i]!='a'&&
            entrada[i]!='E'&&
            entrada[i]!='e'&&
            entrada[i]!='I'&&
            entrada[i]!='i'&&
            entrada[i]!='O'&&
            entrada[i]!='o'&&
            entrada[i]!='U'&&
           ^ entrada[i]!='u'){
        printf("%c", entrada[i]);
        }
    }
    printf("\n");
    
    
    
    return 0;
}
