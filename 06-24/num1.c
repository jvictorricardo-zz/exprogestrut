#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char caractere;
    
    fp = fopen("arq.txt", "a");
    while(1){
        scanf("%c", &caractere);
        if (caractere!='0'){
            fprintf(fp, "%c",caractere);
        }
        else{
            break;
        }
    }
    fclose(fp);
    return 0;
}
