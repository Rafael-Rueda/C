#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
SOMATORA DE FATORIAL – Crie um programa que efetue a leitura de 5 valores inteiros quaisquer
fornecidos pelo usuário, no final o programa deverá apresentar o total do somatório da fatorial de cada
valor lido.
*/

int fatorial(int numero) {
	int i, fat = 1;
	
	if (numero == 0) {
		return 1;
	}
	
	for(i = 0; i < numero; i++) {
		fat = fat * (numero - i);
	}
	
	return fat;
}

int main(int argc, char *argv[]) {
	int c, somatorio = 0;
	int numeros[5];
	
	printf("=-=-=-=-= Somatoria de Fatorial =-=-=-=-=\n");
	printf("Digite 5 valores inteiros quaisquer:\n");
	scanf("%i", &numeros[0]);
	scanf("%i", &numeros[1]);
	scanf("%i", &numeros[2]);
	scanf("%i", &numeros[3]);
	scanf("%i", &numeros[4]);
	
	for (c = 0; c < 5; c++) {
		somatorio += fatorial(numeros[c]);
	}
	
	printf("O somatorio do fatorial de cada valor lido e igual a: %i", somatorio);
	
	return 0;
}
