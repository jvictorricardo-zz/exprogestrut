#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno{
    char matricula[14];
    char nome[50];
    float CR;
}aluno;

void mostraalunos(aluno *lista, int tam);
aluno *novoaluno(aluno *lista, int *tam, int *capacidade);

int main(){
    aluno *lista=NULL;
    FILE *fp;    
    int capacidade = 100, tam=0, esc=0, i;
    char nomearq[50];
    
    //abrindo o arquivo como somente-leitura
    printf("Digite o nome do arquivo:  ");
    scanf("%s", nomearq);
    fp = fopen(nomearq, "rb");
    
    //verificando se o arquivo existe
    if (fp!=NULL){//ele existe
        fread(&tam, sizeof(int), 1, fp);
        if(tam>capacidade) capacidade = tam;
        lista = (aluno *)calloc(capacidade, sizeof(aluno));
        fread(lista, sizeof(aluno), tam, fp);
        fclose(fp);
    }
    else{//ele não existe
        lista = (aluno *)calloc(capacidade, sizeof(aluno));
    }
    
    while(1){
        printf("Bem vindo ao sistema\n[1] Listar todos os alunos\n[2] Inserir um aluno\n[3] Sair\n");
        printf("Deseja realizar qual operação?  ");
        scanf("%d", &esc);
        if(esc==1){
            mostraalunos(lista, tam);
        }
        else if(esc==2){
            lista = novoaluno(lista, &tam, &capacidade);
        }
        else if (esc==3){
            fp = fopen(nomearq, "wb");
            if(fp!=NULL){
                fwrite(&tam, sizeof(int), 1, fp);
                fwrite(lista, sizeof(aluno), tam, fp);
                fclose(fp);
            }
            else{
                printf("Não foi possível salvar seu arquivo! :(\n");
            }
            printf("Até a próxima!\n");
            break;
        }
        else{
            printf("Opção inválida! Selecione novamente.\n");
        }
    }
    return 0;
}


// listar alunos
// inserir aluno


void mostraalunos(aluno *lista, int tam){
    if (tam==0){
        printf("Não há alunos cadastrados!\n");
    }
    else{
        int i;
        for(i=0;i<tam;i++){
            printf("Matrícula: %s\nNome: %sCR: %.2f\n", lista[i].matricula, lista[i].nome, lista[i].CR);
        }
        printf("\n");
    }
}

aluno *novoaluno(aluno *lista, int *tam, int *capacidade){
    char enter;
    if(*tam > (*capacidade-1)){
        *capacidade *= 2;
    }
    printf("Digite a matrícula do aluno:  ");
    scanf("%s", lista[*tam].matricula);
    scanf("%c", &enter);
    printf("Digite o nome:  ");
    fgets(lista[*tam].nome, 50, stdin);
    lista[*tam].nome[sizeof(lista[*tam].nome)-1]='\0';
    printf("Digite o CR:  ");
    scanf("%f", &lista[*tam].CR);
    *tam += 1;
    return lista;
}
