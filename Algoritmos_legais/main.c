#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
FIGURAS GEOM�TRICAS � Crie um programa que seja capaz de calcular a �rea de 4 figuras geom�tricas,
s�o elas, ret�ngulo, tri�ngulo, quadrado e c�rculo, todas as informa��es de dimens�es das figuras
devem ser fornecidas pelo usu�rio do sistema. Ap�s o fornecimento dos dados, o sistema dever�
realizar o c�lculo das �reas de cada figura e exibir os seguintes resultados:
a) A �rea calculada para cada figura geom�trica.
b) A figura geom�trica com menor �rea.
c) A figura geom�trica com maior �rea.
d) Exibir as �reas das figuras geom�tricas de forma crescente (da menor para a maior).
*/

void bubbleSort(int num[], int n) {
	int temp, c, i;
	
	for(c = 0; c < n - 1; c++) {
		for(i = 0; i < n - 1 - c; i++) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}	
	}
}

void bubbleSort2(int num[], int n) {
	int temp, c, i;
	
	for(c = 0; c < n - 1; c++) {
		for(i = (c + 1); i < n; i++) {
			if (num[c] > num[i]) {
				temp = num[c];
				num[c] = num[i];
				num[i] = temp;
			}
		}	
	}
	
}

int binarySearch(int num[], int len, int bs) {
	//Variaveis
	int left, right, mid;
	left = 0;
	right = len - 1;
	
	// 28 38 39 383
	//  0  1  2  3 
	// right = 3; left = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		if (bs == num[mid]) {
			return 1;
		} else if (bs < num[mid]) {
			// bs esta na metade esquerda	
			right = mid - 1;
		} else if (bs > num[mid]) {
			// bs esta na metade direita
			left = mid + 1;
		}
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int c = 0;
	int num[4] = {-1};
	int bs = 0;
	
	printf("Digite quatro valores inteiros:\n");
	scanf("%i", &num[0]);
	scanf("%i", &num[1]);
	scanf("%i", &num[2]);
	scanf("%i", &num[3]);
	
	printf("\n");
	
	// Bubble sort
	printf("**BUBBLE SORT**\n");
	bubbleSort(num, 4);
	
	for (c = 0; c < (sizeof(num) / sizeof(num[0])); c++) {
		printf("%i ", num[c]);
	}
	
	printf("\n\n");
	
	// Binary Search
	printf("**BINARY SEARCH**\n");
	printf("Digite o valor a ser pesquisado na lista de numeros anterior:\n");
	scanf("%i", &bs);
	
	if (binarySearch(num, 4, bs)) {
		printf("O numero %i existe na lista !", bs);
	} else {
		printf("O numero %i nao existe na lista !", bs);
	}
	
	return 0;
}
