#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Marçal, J.
 * Verifica se um valor inteiro é par e maior
 * que 10. O programa faz uso dos conceitos 
 * de tabela verdade.
 */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int val = 0;

	printf("\n");
	printf(":: PROCESSAMENTO ::..\n");
	printf(":: O programa verifica se um número é positivo e maior que 10 ::..\n");
	printf("\n");
	
	// Entrada
	printf("Digite um numero inteiro qualquer:\n");
	scanf("%i", &val);
	
	// Processamento (com uso de tabela verdade)
	if(((val % 2) == 0) && (val > 10)) {
		// Saída
		printf("O valor %i e positivo e maior que 10. \n", val);
	} else {
		// Saída
		printf("O valor %i não é positivo ou maior que 10. \n", val);
	}
	
	system("pause");
	return 0;
}



