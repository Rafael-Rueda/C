#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	float nota1, nota2, media = 0.0;

	printf("\n");
	printf(":: PROCESSAMENTO ::..\n");
	printf(":: Programa calcula a média do aluno ::..\n");
	printf("\n");
	
	printf("Digite o valor da primeira nota :\n");
	scanf("%f", &nota1);
	printf("Digite o valor da segunda nota :\n");
	scanf("%f", &nota2);
	
	media = (nota1 + nota2) / 2;
	if (media < 5.0) {
		printf("A media %2.2f: Reprovado. \n", media);
	} else {
		if ((media >= 5.0) && (media < 7.0)) {
			printf("A media %2.2f: Aprovado: Atencao!. \n", media);
		} else {
			if ((media >= 7.0) && (media < 8.5)) {
				printf("A media %2.2f: Aprovado!. \n", media);
			} else {
				printf("A media %2.2f: Aprovado: Parabens!. \n", media);
			}
		}
	}
	
	system("pause");
	return 0;
}




