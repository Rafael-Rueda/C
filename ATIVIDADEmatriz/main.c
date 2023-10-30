#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
DESCRIÇÃO ATIVIDADE MATRIZ – Crie uma aplicação console para realização de operações sobre uma 
matriz capaz de armazenar ao menos 50 valores inteiros.

Opções do menu:

Carregar matriz com valores aleatórios entre 1 e 40;

Impressão dos valores da matriz.

Linha com maior soma – Deverá percorrer todas e linhas e somar os valores por linha e imprimir o 
número da linha e valor da soma, durante o processamento deverá identificar qual a linha com a 
maior soma e no final do processamento deverá exibir a mensagem informando qual a linha contém 
o maior valor;

Coluna maior número valores pares – Deverá percorrer todas as colunas, imprimir o número de cada uma
 e a quantidade de valores pares, durante o processamento deverá identificar qual a coluna com o
  maior número de valores pares ao término do processamento deverá exibir uma mensagem informando;

Linha com o maior valor – Deverá percorrer cada uma das linhas da matriz e identificar qual das linhas contêm o maior valor.

2 Linhas e 2 Colunas – Solicite do usuário 2 linhas e 2 colunas dentro dos limites da matriz, 
em posse destas informações faça:
VALORES: Imprima o número de cada linha e valores e o número de cada coluna e valores;
SOMAS: Imprima o número de cada linha e coluna e a soma dos valores individualmente;
MAIOR SOMA: Dentre as 4 informações, exiba a com maior valor de soma;

*/
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int matriz[5][10] = {0};
	int opcao = 99;
	
	do {
		printf("..: ATIVIDADE MATRIZ [5x10] :..\n");
		printf("1. Carregar aleatorio (1 a 40)\n");
		printf("2. Imprimir matriz\n");
		printf("3. Linha com maior soma\n");
		printf("4. Coluna maior numero valores pares\n");
		printf("5. Linha com o maior valor\n");
		printf("6. 2 Linhas e 2 Colunas\n");
		
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1: {
				int c, d;
				for (c = 0; c < 5; c++) {
					for(d = 0; d < 10; d++) {
						matriz[c][d] = (rand() % 40) + 1;
					}
				}
				printf("\nValores aleatorios gerados\n\n");
				break;
			}
			case 2: {
				int c, d;
				printf("\nImprimindo valores\n\n");
				for (c = 0; c < 5; c++) {
					for (d = 0; d < 10; d++) {
						printf(">>> [%d x %d] = %d\n", c, d, matriz[c][d]);
					}
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				}
				printf("\n");
				break;
			}
			case 3: {
				int c, d;
				int somalinha[5] = {0};
				int maiorsoma = 0;
				int maiorvalor = 0;
				int linhamaiorvalor = 0;
				printf("\nCalculando...\n");
				for(c = 0; c < 5; c++) {	 
					for(d = 0; d < 10; d++) {
						somalinha[c] = somalinha[c] + matriz[c][d];
						if (maiorvalor < matriz[c][d]) {
							maiorvalor = matriz[c][d];
							linhamaiorvalor = c;
						}
					}
					printf("Soma da Linha %d: %d\n", c, somalinha[c]);
				}
				
				maiorsoma = somalinha[0];
				for (c = 1; c < 5; c++) {
					if (maiorsoma < somalinha[c]) {
						maiorsoma = somalinha[c];
					}
				}
				printf("\nMaior Soma: %d\n", maiorsoma);
				printf("Maior Valor: %d, na linha %d\n\n", maiorvalor, linhamaiorvalor);
				break;
			}
			case 4: {
				int c,d;
				// DC
				// [ 1, 2 , 3 ]   [ 1, 4, 7]
				// [ 4, 5, >6 ]	  [ 2, 5, 8]
				// [ 7, *8, 9 ]   [ 3, 6, 9]
				printf("\n");
				int colunas[10][5];
				for(c=0; c < 5; c++) {
					for(d=0; d < 10; d++) {
						colunas[d][c] = matriz[c][d];
					}
				}
				int paresnacoluna = 0;
				for(c=0; c < 10; c++) {
					printf("\n>>>Coluna %d:", c);
					for(d=0; d < 5; d++) {
						printf(" %d |", colunas[c][d]);
						if (colunas[c][d] % 2 == 0) {
							paresnacoluna++;
						}
					}
					printf("\n-Respectiva quantidade de pares: %d\n", paresnacoluna);
					paresnacoluna = 0;
				}
				printf("\n");
				break;
			}
			case 5: {
				int c, d;
				int maiorvalor = 0;
				int linhamaiorvalor = 0;
				printf("\nCalculando...\n");
				for(c = 0; c < 5; c++) {	 
					for(d = 0; d < 10; d++) {
						if (maiorvalor < matriz[c][d]) {
							maiorvalor = matriz[c][d];
							linhamaiorvalor = c;
						}
					}
				}
				printf("\nMaior Valor: %d, na linha %d\n\n", maiorvalor, linhamaiorvalor);
				break;
			}
			case 6: {
				int linha1, linha2, coluna1, coluna2;
				
				do {
					printf("Digite a primeira linha (valores validos apenas entre 0 e 4): ");
					scanf("%d", &linha1);
					printf("Digite a segunda linha (valores validos apenas entre 0 e 4): ");
					scanf("%d", &linha2);
					
					printf("Digite a primeira coluna (valores validos apenas entre 0 e 9): ");
					scanf("%d", &coluna1);
					printf("Digite a segunda coluna (valores validos apenas entre 0 e 9): ");
					scanf("%d", &coluna2);
					printf("Verificando valores...\n");
				} while(!(linha1 <= 4) || !(linha1 >= 0) || !(linha2 <= 4) || !(linha2 >= 0) || !(coluna1 <= 9) || !(coluna1 >= 0) || !(coluna2 <= 9) || !(coluna2 >= 0));
				
				int colunas[10][5];
				int c,d;
				// Criar matriz de colunas
				for(c=0; c < 5; c++) {
					for(d=0; d < 10; d++) {
						colunas[d][c] = matriz[c][d];
					}
				}
				
				

				int somas[4];
				int soma = 0;
				
				c = linha1;
				printf("\nLinha %d: ", linha1);
				for(d=0; d < 10; d++) {
					printf(" %d |", matriz[c][d]);
					soma += matriz[c][d];
				}
				printf("\nA soma da linha %d, e igual a: %d", linha1, soma);
				somas[0] = soma;
				//
				soma = 0;
				c = linha2;
				printf("\nLinha %d: ", linha2);
				for(d=0; d < 10; d++) {
					printf(" %d |", matriz[c][d]);
					soma += matriz[c][d];
				}
				printf("\nA soma da linha %d, e igual a: %d", linha2, soma);
				somas[1] = soma;
				
				
				soma = 0;
				c = coluna1;
				printf("\nColuna %d: ", coluna1);
				for(d=0; d < 5; d++) {
					printf(" %d |", colunas[c][d]);
					soma += colunas[c][d];
				}
				printf("\nA soma da coluna %d, e igual a: %d", coluna1, soma);
				somas[2] = soma;
				//
				soma = 0;
				c = coluna2;
				printf("\nColuna %d: ", coluna2);
				for(d=0; d < 5; d++) {
					printf(" %d |", colunas[c][d]);
					soma += colunas[c][d];
				}
				printf("\nA soma da coluna %d, e igual a: %d", coluna2, soma);
				somas[3] = soma;
				printf("\n\n");
				
				
				
				int maior = somas[0];
				int maiorindice = 0;
				for(c=0; c < 4; c++) {
					if (somas[c] >= maior) {
						maior = somas[c];
						maiorindice = c;
					}
				}
				switch(maiorindice) {
					case 0: {
						printf("A maior soma e a da linha 1, e e igual a: %d\n\n", maior);
						break;
					}
					case 1: {
						printf("A maior soma e a da linha 2, e e igual a: %d\n\n", maior);
						break;
					}
					case 2: {
						printf("A maior soma e a da coluna 1, e e igual a: %d\n\n", maior);
						break;
					}
					case 3: {
						printf("A maior soma e a da coluna 2, e e igual a: %d\n\n", maior);
						break;
					}
				}
				break;
			}
		}
	} while (opcao != 99);
		
	return 0;
}
