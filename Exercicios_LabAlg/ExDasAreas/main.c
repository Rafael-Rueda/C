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

struct areastruct {
	char nome[20];
	float valor;
};
	
int main(int argc, char *argv[]) {
	float medidas[8];
	struct areastruct areas[4];
	
	int c, i;
	for(c = 0; c <= 6; c +=2) {
		if (c == 0) {
			printf("==== Retangulo ====\n");
		} else if (c == 2) {
			printf("==== Triangulo ====\n");
		} else if (c == 4) {
			printf("==== Quadrado ====\n");
		} else if ( c == 6) {
			printf("==== Circulo ====\n");
		}
		printf("Qual a medida da base ? (Deixe 0 se for circulo)\n");
		scanf("%f", &medidas[c]);
		printf("Qual a medida da altura/raio ?\n");
		scanf("%f", &medidas[c + 1]);
	}
	
	areas[0].valor = medidas[0] * medidas[1];
	strcpy(areas[0].nome, "Retangulo");

	areas[1].valor = medidas[2] * medidas[3] / 2;
	strcpy(areas[1].nome, "Triangulo");
	
	areas[2].valor = medidas[4] * medidas[5];
	strcpy(areas[2].nome, "Quadrado");
	
	areas[3].valor = 3.14 * (medidas[7] * medidas[7]);
	strcpy(areas[3].nome, "Circulo");
	
	// Bubble Sort
	float x, menor = areas[0].valor;
	char y[20];
	
	for(i = 0; i < sizeof(areas) / sizeof(areas[0]); i++) {
		for(c = 0; c < 3; c++) {
		if (areas[c].valor > areas[c + 1].valor) {
			x = areas[c].valor;
			strcpy(y, areas[c].nome);
			areas[c].valor = areas[c + 1].valor;
			strcpy(areas[c].nome, areas[c + 1].nome);
			strcpy(areas[c + 1].nome, y);
			areas[c + 1].valor = x;
		}
	}
	}
	
	for(c=0; c < 4; c++) {
		printf("Area - %s: %f\n", areas[c].nome, areas[c].valor);
	}
	return 0;
}
