#include<stdio.h>
#include<stdlib.h>

int main(){
    int ch=9;
    int *indice;
    
    indice = &ch;
    
    printf("%d\n", *indice);

    return 0;
}
