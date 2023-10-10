#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
IDENTIFICAR MENOR/MAIOR, PERCORRER INTERVALO, CONTAR SOMAR DIVISIVEIS – Crie uma aplicação que deverá solicitar 4 valores inteiros 
em qualquer ordem do usuário, identifique qual é o menor e maior valor e então percorras todos os valores deste intervalo, durante 
o processamento, verifique quantos valores dentro deste intervalo são divisíveis pelos outros dois valores que foram informados, 
o programa deverá então contar e somar todos os valores que são divisíveis.
*/

void bubbleSort(int num[], int n) {
	int x, i, j;
	//Bubble sort
	for(i = 0; i < n - 1; i++) {
		for(j = (i + 1); j < n; j++) {
			if (num[j] < num[i]) {
				x = num[i];
				num[i] = num[j];
				num[j] = x;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int c;
	int numeros[4];
	
	printf("Digite quatro valores inteiros: ");
	for(c = 0; c < 4; c++) {
		scanf("%i", &numeros[c]);
	}
	
	bubbleSort(numeros, 4);
	
	printf("Seus numeros: ");
	for(c = 0; c < 4; c++) {
		printf("%i | ", numeros[c]);
	}
	printf("\nMaior: %i\nMenor: %i\n", numeros[3], numeros[0]);
	
	// Calculo do intervalo [Menor numero, Maior numero]
	
	int contagem = 0, soma = 0;
	
	for(c = numeros[0]; c <= numeros[3]; c++) {
		if (c % numeros[1] == 0 && c % numeros[2] == 0) {
			contagem += 1;
			soma += c;
		}
	}
	
	printf("A contagem dos valores no intervalo [%i, %i] que sao divisiveis por %i e %i e igual a: %i\n", numeros[0], numeros[3], numeros[1], numeros[2], contagem);
	printf("A soma dos valores no intervalo [%i, %i] que sao divisiveis por %i e %i e igual a: %i\n", numeros[0], numeros[3], numeros[1], numeros[2], soma);
	
	return 0;
}
