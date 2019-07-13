#include<stdio.h>
#include<stdlib.h>

int SeqAditiva(int n, int t0, int t1);

int main(){
    int a;
    a = SeqAditiva(4, 1, 2);
    printf("%d", a);
    return 0;
}


int SeqAditiva(int n, int t0, int t1){
    if(n==1) return t0;
    return SeqAditiva(n-1, t1, t0+t1);
}
