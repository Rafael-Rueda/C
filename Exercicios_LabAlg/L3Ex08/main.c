#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int n1,n2,n3,n4,n5;
	int intervalo11, intervalo12, intervalo21, intervalo22;
	
	printf("Digite 5 numeros que nao se repetem:\n");
	printf("(Os dois primeiros corresponderao a um intervalo, os proximos um segundo intervalo, e o ultimo o valor sera analisado com base nos intervalos.)\n\n");
	
	
	printf("Numero 1: "); scanf("%i", &n1);
	printf("Numero 2: "); scanf("%i", &n2);
	if (n1 == n2) {
		printf("Os numeros nao podem se repetir !");
	} else {
		printf("Numero 3: "); scanf("%i", &n3);
		if (n3 == n1 || n3 == n2) {
			printf("Os numeors nao podem se repetir !");
		} else {
			printf("Numero 4: "); scanf("%i", &n4);
			if (n4 == n1 || n4 == n2 || n4 == n3) {
				printf("Os numeros nao podem se repetir !");
			} else {
				printf("Numero 5: "); scanf("%i", &n5);
				if (n5 == n1 || n5 == n2 || n5 == n3 || n5 == n4) {
					printf("Os numeros nao podem se repetir !");
				} else {
					
					if (n1 < n2) {
						intervalo11 = n1;
						intervalo12 = n2;	
					} else {
						intervalo11 = n2;
						intervalo12 = n1;
					}
					
					if (n3 < n4) {
						intervalo21 = n3;
						intervalo22 = n4;	
					} else {
						intervalo21 = n4;
						intervalo22 = n3;
					}
					
					int trava1 = 0, trava2 = 0;
					
					if ((n5 >= intervalo11) && (n5 <= intervalo12)) {
						printf("O numero %i esta no primeiro intervalo (%i - %i)\n", n5, intervalo11, intervalo12);
						trava1 = 1;
					}
					if ((n5 >= intervalo21) && (n5 <= intervalo22)) {
						printf("O numero %i esta no segundo intervalo (%i - %i)\n", n5, intervalo21, intervalo22);
						trava1 = 1;
					}
					
					if ((!trava1) && (!trava2)) {
						printf("O numero %i nao esta em nenhum intervalo\n", n5);
					}
					
				}
			}
		}
	}
	
	
	
	
	return 0;
}
