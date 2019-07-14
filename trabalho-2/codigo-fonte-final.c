#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//declarando as estruturas
typedef struct onibus{
    char nome[50];
    int hora;
	int minuto;
    int assentos[10][4];
    int qtdOcupadas;
}onibus;

typedef struct reserva{
    int numIdent;
	char linha[50];
	int hora;
	int minuto;
	int assento;
}reserva;

//prototipando funções
onibus *criaLinha(onibus *linha , int *quantbus, int adicionar);
reserva *criaReserva(reserva *lista, int *quantReservas, int *qtdOnibus, onibus *linha, int *id);
int cacaReserva(reserva *lista, int *quantReservas, int termo);
reserva *apagarReserva(reserva *lista, int *quantReservas, int *qtdOnibus, onibus *linha, int apagada);

void mostraHora(onibus *linha , int *quantbus, int mostraQ);
void mostraAssento(onibus *linha, int horarioSel);
int taVazio(int matriz[10][4], int poltrona);
void mostraReservas(reserva *lista, int quantReservas);
int existeHorario(onibus *horarios, int limite, int hora, int minuto);
onibus *limpaAssento(onibus *linha,reserva *lista, int *qtdOnibus, int escolha);

//main
int main(){
    int escolha=0, qtdOnibus=0, qtdReservas=0, identificador=0, i=0;
    char pegaEnter, nomearquivo[50];
    onibus *linha=NULL;
    reserva *reservas=NULL;
    FILE *fp;
    
    //leitura de arquivos
    printf("Digite o nome do arquivo a ser lido(um novo será criado caso não exista):  ");
    scanf("%s", nomearquivo);    
    fp = fopen(nomearquivo, "rb");
    if(fp!=NULL){
        fread(&qtdOnibus, sizeof(int), 1, fp);
        fread(&qtdReservas, sizeof(int), 1, fp);
        fread(&identificador, sizeof(int), 1, fp);
        linha = (onibus *)malloc(sizeof(onibus)*qtdOnibus);
        reservas = (reserva *)malloc(sizeof(reserva)*qtdReservas);
        fread(linha, sizeof(onibus), qtdOnibus, fp);
        fread(reservas, sizeof(reserva), qtdReservas, fp);
        fclose(fp);
    }
    else{
        printf("O arquivo não pode ser lido corretamente!\n");
    }
    
    
    //loop do menu
	while(1){
	    fflush(stdin);	    
	    printf("Sistema de reserva de leitos\n");
	    printf("[1] Criar/Adicionar uma linha de ônibus\n[2] Criar uma reserva\n[3] Excluir uma reserva\n[4] Procurar reserva");
	    printf("\n[5] Mostrar o mapa de lugares de um horário\n[6] Salvar alterações\n[7] Sair\n");
	    printf("Digite a operação desejada:  ");
	    scanf("%d", &escolha);
	    switch(escolha){
	    case 1:
            scanf("%c", &pegaEnter);
            system("clear");
            printf("Digite quantos ônibus deseja adicionar: ");
            scanf("%d", &escolha);
            while(escolha<0){
                //verifica se a quantidade é válida
                printf("A quantidade deve ser superior a 0!\nDigite novamente: ");
                scanf("%d", &escolha);
            }
            linha = criaLinha(linha, &qtdOnibus, escolha);
	    break;
	    case 2:
		    scanf("%c", &pegaEnter);
		    system("clear");
		    if(qtdOnibus>0){
		        reservas = criaReserva(reservas, &qtdReservas, &qtdOnibus, linha, &identificador);
	        }
	        else{
	            printf("Criação de reserva não permitida! Adicione pelo menos uma linha antes de realizar essa operação.\n");
	        }		   
	    break;
	    case 3:
	        scanf("%c", &pegaEnter);
	        system("clear");
            if(qtdReservas>0){
                mostraReservas(reservas, qtdReservas);
                printf("Digite o número de identificação da reserva que deseja apagar (de 0 à %d):  ", identificador-1);
                scanf("%d", &escolha);
                while(escolha<0 || escolha>=identificador){
                    printf("Número de identificação inválido, digite novamente:  ");
                    scanf("%d", &escolha);
                }
		        if(cacaReserva(reservas, &qtdReservas, escolha)==0){
                    linha = limpaAssento(linha, reservas, &qtdOnibus, escolha);
                    reservas = apagarReserva(reservas, &qtdReservas, &qtdOnibus, linha, escolha);
                }
                else{
                    printf("Reserva inexistente!\n");
                }
	        }
	        else{
	            printf("Exclusão não permitida! Adicione pelo menos uma reserva antes de realizar essa operação.\n");
	        }
	    break;
	    case 4:
    	    scanf("%c", &pegaEnter);
	        system("clear");
            if(qtdOnibus>0 && qtdReservas>0){
                printf("Digite o número de identificação da reserva que deseja encontrar (de 0 à %d):  ", identificador-1);
                scanf("%d", &escolha);
                while(escolha<0 || escolha>=identificador){
                    printf("Número de identificação inválido, digite novamente:  ");
                    scanf("%d", &escolha);
                }
		        if(cacaReserva(reservas, &qtdReservas, escolha)==0){
                    //encontrando a reserva com o numero de identificação escolhido, após validar ele
                    for(i=0;i<qtdReservas;i++){
                        if(escolha==reservas[i].numIdent){
                            break;
                        }
                    }
                    printf("Reserva encontrada!\n\n");
                    printf("Número de identificação: %d\n", reservas[i].numIdent);
                    printf("Linha: %s\n", reservas[i].linha);
                    printf("Horário de partida:  %02d:%02d\n", reservas[i].hora, reservas[i].minuto);
                    printf("Assento:  %d\n\n", reservas[i].assento);
                }
                else{
                    printf("Reserva inexistente!\n");
                }
	        }
	        else{
	            printf("Busca não permitida! Adicione pelo menos uma reserva antes de realizar essa operação.\n");
	        }
		    
	    break;
	    case 5:
		    scanf("%c", &pegaEnter);
		    system("clear");   
            
            if(qtdOnibus>0){
                //selecionando o horario
                mostraHora(linha, &qtdOnibus, 1);
                printf("Selecione o horário cujas poltronas deseja exibir:  ");
                scanf("%d", &escolha);
                //validando a entrada
                while(escolha<0 || escolha>=qtdOnibus){
                    printf("Seleção inválida! Digite outra vez:  ");
                    scanf("%d", &escolha);
                }
                mostraAssento(linha, escolha);
            }
            else{
                printf("Operação não permitida. Adicione pelo menos uma reserva antes de realizar essa operação.\n");
            }
	    break;
	    case 6:
		    scanf("%c", &pegaEnter);
            system("clear");
		    fp = fopen(nomearquivo, "wb");
            if(fp!=NULL){
                fwrite(&qtdOnibus, sizeof(int), 1, fp);
                fwrite(&qtdReservas, sizeof(int), 1, fp);
                fwrite(&identificador, sizeof(int), 1, fp);
                fwrite(linha, sizeof(onibus), qtdOnibus, fp);
                fwrite(reservas, sizeof(reserva), qtdReservas, fp);
                fclose(fp);
            }
            else{
                printf("O arquivo não pode ser lido corretamente.\n");
            }
	    break;
	    case 7:
		    scanf("%c", &pegaEnter);
            system("clear");
	        printf("Até a próxima!\n");
	        exit(0);
	    break;
	    default:
		    printf("Opção inválida! Tente novamente.\n");
	    break;
	    }
    }

    return 0;
}

//declarando as funções
onibus *criaLinha(onibus *linha , int *quantbus, int adicionar){
    char nome[50], pegaEnter;
    int i=0, j=0, k=0;
    
    int qtdOnibus = *quantbus;
    
    //alocando espaço caso não haja nenhuma linha criada
    if(qtdOnibus==0){
        scanf("%c", &pegaEnter);
        printf("Digite o nome da linha a ser adicionada:  ");
        fgets(nome, 50, stdin);
        nome[strlen(nome)-1]='\0';
        linha = (onibus *)malloc((sizeof(onibus)*adicionar));
        fflush(stdin);
    }
    //criando um vetor auxiliar para receber linha e o novo elemento
    else{
        linha = (onibus *) realloc(linha, sizeof(onibus)*((*quantbus)+2));
        strcpy(nome, linha[0].nome);
    }
    
    //começamos por quantidade de onibus, e paramos no destino
    for(i=qtdOnibus;i<(adicionar+qtdOnibus);i++){
        strcpy(linha[i].nome, nome);
        linha[i].qtdOcupadas=0;
        printf("Digite a hora e minuto em que o ônibus parte(separados por espaço):  ");
        scanf("%d", &linha[i].hora);
        scanf("%d", &linha[i].minuto);
        fflush(stdin);
        while(linha[i].hora < 0 || linha[i].hora>=24 || linha[i].minuto<0 || linha[i].minuto>=60|| existeHorario(linha, i,linha[i].hora, linha[i].minuto)==1){
            printf("Horário inválido, digite novamente:  ");
            scanf("%d", &linha[i].hora);
            scanf("%d", &linha[i].minuto);
            fflush(stdin);
        }
    }
    
    //zerando as assentos da(s) linha(s) adicionada(s)
    for(k=qtdOnibus;k<(qtdOnibus+adicionar);k++){
        for(i=0;i<10;i++){
            for(j=0;j<4;j++){
                linha[*quantbus].assentos[i][j] = 0;
            }
        }
    }
    
    //acrescentando na qtd de onibus adicionados
    *quantbus += adicionar;
    
    //mostrando a linha após a conclusão da operação
    mostraHora(linha, quantbus, 1);
    
    return linha;
}

reserva *criaReserva(reserva *lista, int *quantReservas, int *qtdOnibus, onibus *linha, int *id){
    int quantres=0, i=0, j=0, contador=0, m=0;
    quantres = *quantReservas;
    
    //alocando/realocando espaço para as reservas
    if(quantres==0){
        lista = (reserva *)malloc((sizeof(reserva)));
        fflush(stdin);
    }
    else{
        lista = (reserva *) realloc(lista, sizeof(reserva)*(quantres+1));
    }
    
    mostraHora(linha, qtdOnibus, 0);//mostra os horários da linha adicionada
    
    printf("Digite o número do horário selecionado:  ");
    scanf("%d", &m);
    while(m>*qtdOnibus || m<0){
        printf("Horário inválido! Selecione novamente:  ");
        scanf("%d", &m);
    }
    
    //atribuindo as informações de linha/horário à reserva
    strcpy(lista[quantres].linha, linha[m].nome);
    lista[quantres].hora=linha[m].hora;
    lista[quantres].minuto=linha[m].minuto;
    lista[quantres].numIdent=*id;  
    
    //mostra a disposição atual de assentos
    mostraAssento(linha, m);
    
    printf("Digite o assento desejado:  ");
    scanf("%d", &lista[quantres].assento);
    
    //tratando casos de seleção inválida
    while((taVazio(linha[m].assentos,lista[quantres].assento) == 1 || lista[quantres].assento<=0 || lista[quantres].assento>40)){
        printf("Poltrona já ocupada/inválida! Selecione outra:  ");
        scanf("%d", &lista[quantres].assento);
    }
    
    //ocupando o assento
    contador=1;
    for(i=0;i<10;i++){
        for(j=0;j<4;j++){
            if(contador==lista[quantres].assento){
                linha[m].assentos[i][j] = 1;
            }
            contador++;
        }
    }
    
    *id +=1;
    *quantReservas +=1;
    linha[m].qtdOcupadas += 1;
    
    return lista;
}

int cacaReserva(reserva *lista, int *quantReservas, int termo){
    int i;
    
    //comparando a identificação com o termo dado
    for(i=0;i<*quantReservas;i++){
        if(termo == lista[i].numIdent){
            return 0;
        }
    }
    return 1;
}

onibus *limpaAssento(onibus *linha,reserva *lista, int *qtdOnibus, int escolha){
    int i, j,assento, horario, contador;
    assento = lista[escolha].assento;
    
    //localizar o onibus ao comparar os horários da reserva com os da linha
    for(i=0;i<*qtdOnibus;i++){
        if(linha[i].hora == lista[escolha].hora && linha[i].minuto == lista[escolha].minuto){
            system("clear");
            break;
        }
    }
    
    //esvaziando a poltrona
    horario = i;
    contador=1;
    for(i=0;i<10;i++){
        for(j=0;j<4;j++){
            if(contador==lista[escolha].assento){
                linha[horario].assentos[i][j]=0;
                break;
            }
            contador++;
        }
    }
    
    linha[horario].qtdOcupadas -= 1;
    
    return linha;
}

reserva *apagarReserva(reserva *lista, int *quantReservas, int *qtdOnibus, onibus *linha, int apagada){
    int i,assento;
    
    assento = lista[apagada].assento;
    
    //localizar o onibus ao comparar os horários da reserva com os da linha
    for(i=0;i<*qtdOnibus;i++){
        if(linha[i].hora == lista[apagada].hora && linha[i].minuto == lista[apagada].minuto){
            system("clear");
            break;
        }
    }
    
    //apagando a reserva
    for(i=apagada;i<(*quantReservas-1);i++){
            memcpy(&lista[i], &lista[i+1], sizeof(reserva));
    }
    
    *quantReservas -= 1;
    
    return lista;
}

//Funções extra

void mostraHora(onibus *linha , int *quantbus, int mostraQ){
    int i=0, qtdOnibus = *quantbus;
    
    printf("\nLinha %s === Horários:\n", linha[0].nome);
    for(i=0;i<qtdOnibus;i++){
        printf("[%02d] %02d:%02d\n", i,linha[i].hora, linha[i].minuto);
        if(mostraQ==0){
            printf("Quantidade de assentos ocupados: %d\n\n", linha[i].qtdOcupadas);
        }
    }
    printf("\n");
}

void mostraAssento(onibus *linha, int horarioSel){ //recebe a linha e a linha selecionada
    int contador=1, i, j;
    
    printf("\nMapa de lugares:\n\n");
    //loop percorre a matriz de poltronas, verificando quais estão vazias e exibindo a organização
    for(i=0;i<10;i++){
        printf("|");
        for(j=0;j<4;j++){
            if (linha[horarioSel].assentos[i][j] == 0){
                printf("\t%d\t", contador);
            }
            else{//se estiver ocupada
                printf("\t*\t");
            }
            contador++;
        }
        printf("|\n");
    }
    printf("\n");
}

int taVazio(int matriz[10][4], int poltrona){
    int i, j, contador=1;
    
    //percorre a matriz de poltronas verificando se a poltrona dada está vazia ou não e retorna o resultado
    for(i=0;i<10;i++){
        for(j=0;j<4;j++){
            if (contador == poltrona){
                if(matriz[i][j] == 0){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            contador++;
        }
    }
    return 0;
}

void mostraReservas(reserva *lista, int quantReservas){
    int i;
    
    printf("\nReservas feitas:\n");
    for(i=0;i<quantReservas;i++){
        printf("\nNúmero de identificação: %d\n", lista[i].numIdent);
        printf("Linha: %s\n", lista[i].linha);
        printf("Horário de partida:  %02d:%02d\n", lista[i].hora, lista[i].minuto);
        printf("Assento:  %d\n\n", lista[i].assento);
    }
}

int existeHorario(onibus *horarios, int limite, int hora, int minuto){
    int i;
    
    //verifica se o horário a ser adicionado já existe na linha
    for(i=0;i<limite;i++){
        if(horarios[i].hora==hora&&horarios[i].minuto==minuto){
            return 1;
        }
    }
    return 0;
}
