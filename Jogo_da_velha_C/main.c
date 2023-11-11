#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Procedimentos
void imprimir_tabuleiro(char tabuleiro[3][3][2]) {
	int i, j;			
	for (i = 0; i < 3; i++) {
		printf("[ ");
		for(j = 0; j < 3; j++) {
			if (j == 2) {
				printf("%s", tabuleiro[i][j]);
				break;
			}
			printf("%s | ", tabuleiro[i][j]);
		}
		printf(" ]\n");
	}
}

void inicializar(int tabuleiro[3][3], char tabuleiro_display[3][3][2]) {
	int i,j;
	for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            strcpy(tabuleiro_display[i][j], "-");
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = -1;
        }
    }
}

// Funções
bool verifica_coluna(int tabuleiro[3][3]) {
	int i,j;
	
	for(i = 0; i < 3; i++) {
		int lista_coluna[3] = {-1};
		for(j = 0; j < 3; j++) {
			lista_coluna[j] = tabuleiro[j][i];
		}
		if (lista_coluna[0] == lista_coluna[1] && lista_coluna[0] == lista_coluna[2] && lista_coluna[0] != -1) {
			return true;
		}
	}
	return false;
}

bool verifica_linha(int tabuleiro[3][3]) {
	int i,j;
	
	for(i = 0; i < 3; i++) {
		int lista_linha[3] = {-1};
		for(j = 0; j < 3; j++) {
			lista_linha[j] = tabuleiro[i][j];
		}
		if (lista_linha[0] == lista_linha[1] && lista_linha[0] == lista_linha[2] && lista_linha[0] != -1) {
			return true;
		}
	}
	return false;
}

bool verifica_dp(int tabuleiro[3][3]) {
	int i,j;
	int lista_dp[3] = {-1};
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if (i == j) {
				lista_dp[j] = tabuleiro[i][j];
			}
		}
	}
	if (lista_dp[0] == lista_dp[1] && lista_dp[0] == lista_dp[2] && lista_dp[0] != -1) {
		return true;
	}
	return false;
}

bool verifica_ds(int tabuleiro[3][3]) {
	int i,j;
	int lista_ds[3] = {-1};
	
	for(i = 0; i < 3; i++) {	
		for(j = 0; j < 3; j++) {
			if (i + j == 2) {
				lista_ds[j] = tabuleiro[i][j];
			}
		}
	}
	if (lista_ds[0] == lista_ds[1] && lista_ds[0] == lista_ds[2] && lista_ds[0] != -1) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opcao = 99, partida = 1;
	
	do {
		printf("\n.:: Jogo da velha ::.\n");
		printf("1. Jogar com um amigo\n");
		printf("2. Instruções para jogar\n");
		printf("3. Exibir regras\n");
		printf("99. Sair\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:  {
				printf("=-=-=-=-= Partida %d =-=-=-=-=\n\n", partida);
				partida++;
				
				int tabuleiro[3][3];
				char tabuleiro_display[3][3][2];
				int i,j;
				
				inicializar(tabuleiro, tabuleiro_display);		    
				imprimir_tabuleiro(tabuleiro_display);
				
				bool velha = false;
				bool ganhou = false;
				
				
				while (velha == false && ganhou == false) {
					int c;
					int linha, coluna;
					
					for (c = 1; c < 3; c++) {
						while (true) {
							printf("\nJogador %d:\n", c);
							printf("Digite a linha e a coluna da sua jogada (ex: linha: 0 coluna: 2)\n");
							printf("Linha: ");
							scanf("%d", &linha);
							printf("Coluna: ");
							scanf("%d", &coluna);
							
							if (linha > 2 || linha < 0 || coluna > 2 || coluna < 0) {
								printf(">>> Digite valores validos (entre 0 e 2) !\n");
								continue;
							}
									
							if (tabuleiro[linha][coluna] != -1) {
								printf(">>> A casa precisa estar vazia (a escolhida já foi selecionada)\n");
								continue;
							}
							break;
						}
						
						// Adiciona as jogadas ao tabuleiro
						tabuleiro[linha][coluna] = (c - 1);
						if (c == 1) {
							strcpy(tabuleiro_display[linha][coluna], "O");
						} else if (c == 2) {
							strcpy(tabuleiro_display[linha][coluna], "X");
						}
					
						imprimir_tabuleiro(tabuleiro_display);
        				
						// Verifica se houve um vencedor					
						ganhou = verifica_coluna(tabuleiro);
						if (ganhou) {
							printf(">>> Jogador %d ganhou!\n", c);
							break;
						}
						ganhou = verifica_linha(tabuleiro);
						if (ganhou) {
							printf(">>> Jogador %d ganhou!\n", c);
							break;
						}
						ganhou = verifica_dp(tabuleiro);
						if (ganhou) {
							printf(">>> Jogador %d ganhou!\n", c);
							break;
						}
						ganhou = verifica_ds(tabuleiro);
						if (ganhou) {
							printf(">>> Jogador %d ganhou!\n", c);
							break;
						}
						
						// Verifica se o jogo empatou ou nao
						velha = true;							
						for(i=0;i<3;i++) {
							for(j=0;j<3;j++) {
								if (tabuleiro[i][j] == -1) {
									velha = false;
									break;
								}
							}
							if (velha == false) {
								break;
							}
						}
						if (velha) {
					        printf(">>> O jogo empatou ! Ninguém ganhou !\n");
					        break;
        				}
        				
					}
					
				}
				
				break;
			}
			case 2: {
				printf("Cada jogador vai ter o seu turno para escolher a posição que quer jogar.\n");
				printf("Você, como jogador, deverá informar qual linha e qual coluna quer colocar a sua peça.\n");
				printf("Boa sorte !\n");
				break;
			}
			case 3: {
				printf("Voce sabe como funciona um jogo da velha... :/\n");
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

