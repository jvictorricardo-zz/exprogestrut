#include<stdio.h>
#include<string.h>

//declarando o tipo aluno
typedef struct aluno{
    char nome[50];
    char matricula[13];
    float CR;
}aluno;

//protótipos das funções
void imprime(aluno *v, int i);
void leia(aluno *v, int i);
int comparaNome(aluno *v, int i, int j);
int comparaMatricula(aluno *v, int i, int j);
int comparaCr(aluno *v, int i, int j);
void troca(aluno *v, int i, int j);
void insertionSort(aluno *v, int tam, int (*comp)(aluno *, int, int));


int main(){
    aluno v[10];
    int i=0, opc=0;
    
    //leitura das informações
    printf("Entrada de dados:\n");
    for(i=0;i<10;i++){
        leia(v, i);
    }
    
    //loop da ordenação
    while(opc!=4){
        printf("Selecione por qual critério deseja ordenar\n[1] Por nome\n[2] Por Matrícula\n[3] Por CR\n==>  ");
        scanf("%d", &opc);
        if(opc==1){
            insertionSort(v, 10, comparaNome);
            for(i=0;i<10;i++){
                imprime(v, i);
            }
        }
        else if(opc==2){
            insertionSort(v, 10, comparaMatricula);
            for(i=0;i<10;i++){
                imprime(v, i);
            }
        }
        else if(opc==2){
            insertionSort(v, 10, comparaCr);
            for(i=0;i<10;i++){
                imprime(v, i);
            }
        }
        else{
            printf("Opção inválida! Selecione novamente\n");
        }
    }
    
    
    return 0;
}

void imprime(aluno *v, int i){
	printf("Nome: %s\nMatrícula: %s\nCR: %.2f\n\n", v[i].nome, v[i].matricula, v[i].CR);
}


void leia(aluno *v, int i){
    char enter;
    printf("Digite o nome:  ");
    fgets(v[i].nome, 50, stdin);
    printf("Digite a matrícula:  ");
    fgets(v[i].matricula, 13, stdin);
    printf("Digite o CR: ");
    scanf("%f", &(v[i].CR));
    scanf("%c", &enter);
}



int comparaNome(aluno *v, int i, int j){
    return strcmp(v[i].nome, v[j].nome);
}

int comparaMatricula(aluno *v, int i, int j){
    return strcmp(v[i].matricula, v[j].matricula);
}

int comparaCr(aluno *v, int i, int j){
    if (v[i].CR > v[j].CR) return 1;
    else if (v[i].CR < v[j].CR) return -1;
    else return 0;
}



void troca(aluno *v, int i, int j){
    aluno aux;
    memcpy(&aux, &v[i], sizeof(aluno));//queremos o cont. não a caixinha
    memcpy(&v[i], &v[j], sizeof(aluno));
    memcpy(&v[j], &aux, sizeof(aluno));
}


//passamos o ponteiro da função, assim podemos usar um só programa para qualquer ordenação
void insertionSort(aluno *v, int tam, int (*comp)(aluno *, int, int)){
    int i, j;
    for(i=1;i<tam;i++){
        for(j=i;j>0;j--){
            if(comp(v, j-1, j)>0){
                troca(v, j-1, j);
            }
            else break;
        }
    }
}
