#include <stdio.h>

int main(int argc, char *argv[]) {
    
    // Variaveis
    float total;

    // Entrada
    printf("Digite o total a pagar pela conta: ");
    scanf("%f", &total);

    // Processamento
    float partial;
    partial = (total * 1.1) / 3;

    // Saida
    printf("O total que cada um ira pagar, incluindo a taxa de servico, e: %f", partial);

    return 0;
}