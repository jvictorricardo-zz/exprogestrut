#include <stdio.h>
#include <stdlib.h> 

int **criamat(int linhas, int col);
void mostramat(int **matriz, int linhas, int colunas);

int main() {
	int n, m;
	int **mat;

	printf("Quantas linhas deseja:  ");
	scanf("%d", &n);
	printf("Quantas colunas deseja:  ");
	scanf("%d", &m);

	mat = criamat(n, m);
	mostramat(mat, n, m);

	return 0;
}

int **criamat(int linhas, int col) {
	int i, j;
	int **mat;

	mat = (int **)malloc(linhas * sizeof(int *));

	for (i = 0; i < linhas; i++) {
		mat[i] = (int *)malloc(col * sizeof(int));
	}

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < col; j++) {
			printf("Digite o elemento que deseja inserir em [%d][%d]:  ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}

void mostramat(int **matriz, int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++) {
		printf("|");
		for (j = 0; j < colunas; j++) {
			printf(" %d ", matriz[i][j]);
		}
		printf("|\n");
	}
}
