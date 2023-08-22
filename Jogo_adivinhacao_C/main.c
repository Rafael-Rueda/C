#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	printf("*************************\n");
	printf("* Jogo de adivinhacao ! *\n");
	printf("*************************\n");
	
	int numero_secreto = rand() % 100 + 1;
	int chute;
	while (chute != numero_secreto) {
		printf("Digite o seu chute: ");
		scanf("%d", &chute);
		if (chute != numero_secreto){
			printf("Voce errou !\n");
			if (chute > numero_secreto) {
				printf("O numero secreto e menor !");
			} else {
				printf("O numero secreto e maior !");
			}
		} else {
			printf("Parabens, voce acertou o numero secreto !\n");
		}
	}
	
	return 0;
} 
