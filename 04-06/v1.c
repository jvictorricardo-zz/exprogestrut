#include<stdio.h>
#include<stdlib.h>

int main(){
    int *v;
    int n, i;
    printf("digite n");
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        printf("Digita aí meu parça:  ");
        scanf("%d", &v[i]);
    }
    for(i=0;i<n;i++){
        printf("V[%d] = %d\n", i, v[i]);        
    }
    return 0;
}
