#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
IDENTIFICAR MENOR/MAIOR, PERCORRER INTERVALO, CONTAR SOMAR DIVISIVEIS – Crie uma
aplicação que deverá solicitar 4 valores inteiros em qualquer ordem do usuário, identifique qual é o
menor e maior valor e então percorras todos os valores deste intervalo, durante o processamento,
verifique quantos valores dentro deste intervalo são divisíveis pelos outros dois valores que foram
informados, o programa deverá então contar e somar todos os valores que são divisíveis.

*/
	
int main(int argc, char *argv[]) {
	int temp, c, i, acumulador = 0, contador = 0;
	int num[4];
	
	printf("Digite quatro valores inteiros:\n");
	scanf("%i", &num[0]);
	scanf("%i", &num[1]);
	scanf("%i", &num[2]);
	scanf("%i", &num[3]);
	
	// Bubble sort
	for(c = 0; c < 3; c++) {
		for(i = 0; i < 3; i++) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}	
	}
	printf("Seus numeros: %i %i %i %i\n", num[0], num[1], num[2], num[3]);
	
	for (c = num[0]; c <= num[3]; c++) {
		if (c % num[1] == 0 && c % num[2] == 0) {
			contador += 1;
			acumulador += c;
		}
	}
	
	printf("A quantidade de valores no intervalo dos dois extremos fornecidos (%i e %i), que sao divisiveis por %i e %i, e igual a: %i\n", num[0], num[3], num[1], num[2], contador);
	printf("A soma entre somente esses valores divisiveis e igual a: %i\n", acumulador);
	return 0;
}
