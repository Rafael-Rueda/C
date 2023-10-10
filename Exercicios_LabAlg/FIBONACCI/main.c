#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
FIBONACCI – Crie uma que apresente a série Fibonacci até o décimo quinto termo. A série Fibonacci é
formada pela sequência: 1, 1, 2, 3, 5, 8, 13, 21, 34, ... etc. Esta série se caracteriza pela soma de um
termo posterior com o seu anterior subsequente.
*/

int main(int argc, char *argv[]) {
	int c = 0, fibo = 1, ant1 = 0, ant2 = 0;
	
	printf("Sequencia de fibonacci ate o 15 termo:\n");
	for (c = 0; c < 15; c++) {		
		fibo = ant1 + ant2;
		if (fibo == 0) {
			fibo = 1;
		}
		ant2 = ant1;
		ant1 = fibo;
		
		printf("%i | ", fibo);
	}
	return 0;
}
