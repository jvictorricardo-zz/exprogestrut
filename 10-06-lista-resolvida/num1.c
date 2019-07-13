#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i, par=0, imp=0;
    int *nums;

    printf("Digite quantos números deseja digitar:  ");
    scanf("%d", &n);
    while(n<0){
        printf("Opção inválida! Digite novamente:  ");
        scanf("%d", &n);
    }
    
    nums = (int *) malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        printf("Digite um número:  ");
        scanf("%d", &nums[i]);
        if(nums[i]%2==0){
            par++;
        }
        else{
            imp++;
        }
    }

    printf("Quant. de pares: %d\nQuant. de ímpares: %d\n", par, imp);

    return 0;
}
