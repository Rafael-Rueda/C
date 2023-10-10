#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
GRAOS DE TRIGO NO TABULEIRO � Elabore um programa que efetue o c�lculo e no final apresente o
somat�rio do n�mero de gr�os de tric� que se pode obter num tabuleiro de xadrez (8x8), o programa
dever� obedecer a seguinte regra: colocar um gr�o de trigo no primeiro quadrado e nos quadrados
seguintes o dobro do quadrado anterior. Ou seja, no primeiro quadro coloca-se 1 gr�o, no segundo
quadro colocam-se 2 gr�os (neste momento t�m-se 3 gr�os), no terceiro quadro colocam-se 4 gr�os
(agora tem-se 7), no quarto quadro colocam-se 8 gr�os (agora tem-se 15) at� atingir o sexag�simo
quarto quadro (exerc�cio baseado no cap�tulo 16 do livro �O homem que calculava� de Malba Tahan).
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
