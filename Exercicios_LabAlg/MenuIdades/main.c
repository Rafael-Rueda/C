#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	int opcao = 9;
	int idades[8] = {0};
	int lenidades = sizeof(idades) / sizeof(idades[0]);
	
	do {
		printf("\n.:: Tabela de idades ::.\n");
		printf("1. Zerar\n");
		printf("2. Carregar\n");
		printf("3. Imprimir\n");
		printf("4. Somar\n");
		printf("5. Pares\n");
		printf("6. Contar pares\n");
		printf("7. Somar pares\n");
		printf("8. Menores de idade\n");
		printf("9. Contar maiores de idade\n");
		printf("10. Somar maiores de idade\n");
		printf("99. Sair\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:  {
				int i;
				for(i = 0; i < lenidades; i++) {
					idades[i] = 0;
				}
				printf(">>> Idades zeradas\n");
				break;
			}
			case 2: {
				int i;
				for(i = 0; i < lenidades; i++) {
					printf(">>> Idade %d = ", i);
					scanf("%d", &idades[i]);
				}
				break;
			}
			case 3: {
				int i;
				for(i = 0; i < lenidades; i++) {
					printf(">>> Idade %d = %d\n", i, idades[i]);
				}
				break;
			}
			case 4: {
				int i, soma = 0;
				for(i = 0; i < lenidades; i++) {
					soma += idades[i];
				}
				printf(">>> A soma das idades e: %d\n", soma);
				break;
			}
			case 5: {
				int i;
				printf(".:: Idades pares ::.\n");
				for(i = 0; i < lenidades; i++) {
					if (idades[i] % 2 == 0) {
						printf(">>> Idade %d = %d\n", i, idades[i]);
					}
				}
				break;
			}
			case 6: {
				int i, contador = 0;
				for(i = 0; i < lenidades; i++) {
					if (idades[i] % 2 == 0) {
						contador += 1;
					}
				}
				printf(">>> A quantidade de idades pares e: %d\n", contador);
				break;
			}
			case 7: {
				int i, soma = 0;
				for(i = 0; i < lenidades; i++) {
					if (idades[i] % 2 == 0) {
						soma += idades[i];
					}					
				}
				printf(">>> A soma das idades pares e: %d\n", soma);
				break;
			}
			case 8: {
				int i;
				printf(" .:: Menores de idade ::.\n");
				for(i = 0; i < lenidades; i++) {
					if (idades[i] < 18) {
						printf(">>> Idade %d = %d\n", i, idades[i]);
					}					
				}
				break;
			}
			case 9: {
				int i, contador = 0;
				for(i = 0; i < lenidades; i++) {
					if (idades[i] >= 18) {
						contador += 1;
					}					
				}
				printf(">>> A quantidade de idades maiores de idade e: %d\n", contador);
				break;
			}
			case 10: {
				int i, soma = 0;
				for(i = 0; i < lenidades; i++) {
					if (idades[i] >= 18) {
						soma += idades[i];
					}					
				}
				printf(">>> A soma das idades dos maiores de idade e: %d\n", soma);
				break;
			}
			case 99: {
				printf(">>> Saindo...\n");
				break;
			}
			default: {
				printf("Digite uma opcao valida !\n");
				break;
			}
		}
	} while (opcao != 99);
	
	return 0;
}
