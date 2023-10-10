#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
GRAOS DE TRIGO NO TABULEIRO – Elabore um programa que efetue o cálculo e no final apresente o
somatório do número de grãos de tricô que se pode obter num tabuleiro de xadrez (8x8), o programa
deverá obedecer a seguinte regra: colocar um grão de trigo no primeiro quadrado e nos quadrados
seguintes o dobro do quadrado anterior. Ou seja, no primeiro quadro coloca-se 1 grão, no segundo
quadro colocam-se 2 grãos (neste momento têm-se 3 grãos), no terceiro quadro colocam-se 4 grãos
(agora tem-se 7), no quarto quadro colocam-se 8 grãos (agora tem-se 15) até atingir o sexagésimo
quarto quadro (exercício baseado no capítulo 16 do livro “O homem que calculava” de Malba Tahan).
*/

int main(int argc, char *argv[]) {
	
	int c;
	unsigned long long int grao = 1, soma = 0;
	
	for(c = 0; c < 64; c++) {
		soma += grao;
		printf("%llu | ", grao);
		grao *= 2;
		
	}
	
	printf("\n\n");
	printf("Soma total de graos: %llu\n", soma);
	
	return 0;
}
