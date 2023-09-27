#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
MENU DE OPÇÕES COM SUB-MENU – Crie uma aplicação que consiste em um menu com sub-menus,
esta aplicação deverá corresponder a um sistema de cadastro conforme o exemplo abaixo, por hora,
o sistema de menu deverá apenas apresentar mensagens dizendo “Pressionada a opção XX” após
seleção de cada opção, note também que ao entrar em um determinado sub-menu, o sistema deverá
ficar neste até sair, e quando sair dele deve voltar para o menu principal. Dica: Utilize um looping para
o menu principal, dentro dele, identifique a sub-opção digitada, e então crie outro looping interno para
controle das opções dos sub-menus.
*/
	
int main(int argc, char *argv[]) {
	int opcao = 0;
	while (opcao != 9) {
		printf("..:: MENU SISTEMA CLIENTES ::..\n");
		printf("Digite sua opcao:\n");
		printf("1.Clientes\n2.Fornecedores\n3.Cidades\n9.Sair\n\n");
		scanf("%i", &opcao);
		
		if (opcao == 1) {
			while (opcao != 19) {
				printf("..:: Clientes ::..\n");
				printf("Digite sua opcao:\n");
				printf("11. Cadastrar cliente\n12.Alterar cliente\n13.Pesquisar cliente\n14.Excluir cliente\n19.Sair\n\n");
				scanf("%i", &opcao);
				
				if (opcao == 11) {
					printf("Pressionada a opcao 11: Cadastrar cliente");
					break;
				} else if (opcao == 12) {
					printf("Pressionada a opcao 12: Alterar cliente");
					break;
				} else if (opcao == 13) {
					printf("Pressionada a opcao 13: Pesquisar cliente");
					break;
				} else if (opcao == 14) {
					printf("Pressionada a opcao 14: Excluir cliente");
					break;
				} else if (opcao == 19) {
					break;
				} else {
					printf("Opcao invalida !\n");
					continue;
				}
			}	
		} else if (opcao == 2) {
			while (opcao != 29) {
				printf("..:: Fornecedores ::..\n");
				printf("Digite sua opcao:\n");
				printf("21. Cadastrar fornecedor\n22.Alterar fornecedor\n23.Pesquisar fornecedor\n24.Excluir fornecedor\n29.Sair\n\n");
				scanf("%i", &opcao);
				
				if (opcao == 21) {
					printf("Pressionada a opcao 21: Cadastrar fornecedor");
					break;
				} else if (opcao == 22) {
					printf("Pressionada a opcao 22: Alterar fornecedor");
					break;
				} else if (opcao == 23) {
					printf("Pressionada a opcao 23: Pesquisar fornecedor");
					break;
				} else if (opcao == 24) {
					printf("Pressionada a opcao 24: Excluir fornecedor");
					break;
				} else if (opcao == 29) {
					break;
				} else {
					printf("Opcao invalida !\n");
					continue;
				}
			}	
		} else if (opcao == 3) {
			while (opcao != 29) {
				printf("..:: Cidades ::..\n");
				printf("Digite sua opcao:\n");
				printf("31. Cadastrar cidade\n32.Alterar cidade\n33.Pesquisar cidade\n34.Excluir cidade\n39.Sair\n\n");
				scanf("%i", &opcao);
				
				if (opcao == 31) {
					printf("Pressionada a opcao 31: Cadastrar cidade");
					break;
				} else if (opcao == 32) {
					printf("Pressionada a opcao 32: Alterar cidade");
					break;
				} else if (opcao == 33) {
					printf("Pressionada a opcao 33: Pesquisar cidade");
					break;
				} else if (opcao == 34) {
					printf("Pressionada a opcao 34: Excluir cidade");
					break;
				} else if (opcao == 39) {
					break;
				} else {
					printf("Opcao invalida !\n");
					continue;
				}
			}
		} else if (opcao == 9) {
			break;
		}else {
			printf("Opcao invalida !\n");
			continue;
		}
		
		if (opcao != 19 && opcao != 29 && opcao != 39) {
			break;
		}
	}
	return 0;
}
