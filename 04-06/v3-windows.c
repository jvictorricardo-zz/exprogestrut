#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

int **criamat(int linhas, int col);
void mostramat(int **matriz, int linhas, int colunas);

int main() {
	int n, m;
	int **mat;

	setlocale(LC_ALL, "Portuguese");  // para problemas de acentuação 

	printf("Quantas linhas deseja:  ");
	scanf_s("%d", &n);
	printf("Quantas colunas deseja:  ");
	scanf_s("%d", &m);

	mat = criamat(n, m);
	mostramat(mat, n, m);

	system("pause");

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
			scanf_s("%d", &mat[i][j]);
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