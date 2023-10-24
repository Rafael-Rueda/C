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
	int pontos = 1000;
	int chute;
	while (chute != numero_secreto) {
		printf("\nDigite o seu chute: ");
		scanf("%d", &chute);
		if (chute != numero_secreto){
			printf("Voce errou !\n");
			pontos -= abs(chute - numero_secreto);
			if (chute > numero_secreto) {
				printf("O numero secreto e menor !");
			} else {
				printf("O numero secreto e maior !");
			}
		} else {
			printf("Parabens, voce acertou o numero secreto !\n");
		}
	}
	
	printf("Pontuacao: %d pontos !", pontos);
	
	return 0;
} 
