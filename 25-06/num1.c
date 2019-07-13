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
    aluno *lista=NULL, A;
    FILE *fp;    
    int capacidade = 100, tam=0, esc=0, i=0, j=0;
    char nomearq[50];
    
    //abrindo o arquivo como somente-leitura
    printf("Digite o nome do arquivo:  ");
    scanf("%s", nomearq);
    fp = fopen(nomearq, "rb");
    
    //verificando se o arquivo existe
    if (fp!=NULL){//ele existe
        fread(&tam, sizeof(int), 1, fp);
        if(tam>capacidade) capacidade = tam;
        lista = (aluno *)calloc(capacidade, sizeof(aluno));//aloca-se o valor antes de ler
        fread(lista, sizeof(aluno), tam, fp);
        fclose(fp);
    }
    else{//ele não existe
        lista = (aluno *)calloc(capacidade, sizeof(aluno));
    }
    
    while(1){
        printf("Bem vindo ao sistema\n[1] Listar todos os alunos\n[2] Inserir um aluno\n[3] Resgatar um aluno no arquivo\n[4] Sair\n");
        printf("Deseja realizar qual operação?  ");
        scanf("%d", &esc);
        if(esc==1){//mostra os alunos
            mostraalunos(lista, tam);
        }
        else if(esc==2){//inserir um aluno
            lista = novoaluno(lista, &tam, &capacidade);
        }
        else if (esc==3){
            fp = fopen(nomearq, "rb");
            if(fp!=NULL){
                printf("Digite qual posição deseja resgatar (entre 0 e %d):  ", tam-1);
                scanf("%d", &j);
                while(j<0 && j>=tam){
                    printf("Número inválido! Digite outro:  ");
                    scanf("%d", &j);
                }
                //sintaxe fseek()
                //fseek(*ptr, size_t numbytes, int ponto_partida);
                //SEEK_SET -- COMEÇO DO ARQUIVO
                //SEEK_CUR -- POSIÇÃO ATUAL DO PONTEIRO
                //SEEK_END -- FIM DO ARQUIVO
                fseek(fp, sizeof(int), SEEK_SET);//DESLOCANDO O PONTEIRO DO ARQUIVO ATÉ O VETOR DOS ALUNOS
                fseek(fp, sizeof(aluno)*j, SEEK_CUR);
                fread(&A, sizeof(aluno), 1, fp);
                //assim que terminar de ler, o ponteiro de arquivo tá no proximo elemento do vetor;
                printf("Matrícula: %s\nNome: %s\nCR: %.2f\n", A.matricula, A.nome, A.CR);
                fclose(fp);
            }
            else{
                printf("Não foi possível ler o arquivo.\n");
            }
            
//          fread(%A, sizeof(aluno), 1, fp);
//          sintaxe do fread              
        }
        else if (esc==4){//sair
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
