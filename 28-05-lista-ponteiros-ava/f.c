#include<stdio.h>
#include<stdlib.h>

void hm(int mnts, int *h, int *m);

int main(){
    int tempo, horas, mins;
    printf("Digite o tempo em minutos:  ");
    scanf("%d", &tempo);
    hm(tempo, &horas, &mins);
    printf("%d minutos equivalem a %d hora(s) e %d minuto(s)\n", tempo, horas, mins);
    return 0;
}

void hm(int mnts, int *h, int *m){
    int horas, mins;
    horas = mnts/60;
    mins = mnts%60;
    *h = horas;
    *m = mins;
}
