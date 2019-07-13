#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, n, num, fat;
    float s=0;
    
    printf("Digite n:  ");
    scanf("%d", &n);
    while(n<1){
        printf("Digite n:  ");
        scanf("%d", &n);
    } 
    
    for(i=0;i<n;i++){
        fat = 1;
        for(j=1;j<=i+1;j++){
            fat*=j;
        }
        s += (n-1)/(float)fat;
    }
    
    printf("Resultado: %.2f\n", s);
    
    return 0;
}
