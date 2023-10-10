#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
BASE E EXPOENTE – Crie um programa que apresente como resultado o valor de uma potência de uma
base qualquer elevada a um expoente qualquer, ou seja, BE, em que B é o valor da BASE e E o valor do
EXPOENTE. Os valores da base e do expoente devem ser fornecidos pelo usuário. Dica: Inicie com
valore de base e expoente baixos, como por exemplo base 3 e expoente 4, 34 = 81.
*/

int main(int argc, char *argv[]) {
	float base, expoente, resultado;
	
	printf("=-=-=-=-= Base e Expoente =-=-=-=-=\n");
	printf("Digite a base: ");
	scanf("%f", &base);
	printf("Digite o expoente: ");
	scanf("%f", &expoente);
	
	resultado = pow(base, expoente);
	printf("%.0f%.0f = %.0f", base, expoente, resultado);
	
	return 0;
}
