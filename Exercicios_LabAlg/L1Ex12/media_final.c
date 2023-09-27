#include <stdio.h>

int main(int argc, char *argv[]) {
    float notas[7];
    float pesos[7] = {0.2, 0.2, 0.6, 0.2, 0.2, 0.2, 0.4};
    float n1 = 0, n2 = 0, mf;
    while(1) {
        int entrada_invalida = 0;

        printf("========== Nota da NP1 ==========\n");
        printf("Atividades: ");
        scanf("%f", &notas[0]);
        printf("EAD (nota): ");
        scanf("%f", &notas[1]);
        printf("Avaliacao: ");
        scanf("%f", &notas[2]);
        printf("========== Nota da NP2 ==========\n");
        printf("Atividades: ");
        scanf("%f", &notas[3]);
        printf("EAD (nota): ");
        scanf("%f", &notas[4]);
        printf("Avaliacao: ");
        scanf("%f", &notas[5]);
        printf("Pluri: ");
        scanf("%f", &notas[6]);

        for (int c = 0; c < sizeof(notas) / sizeof(notas[0]); c++) {
            if (notas[c] > 10) {
                printf("Digite valores de notas validos !\n");
                entrada_invalida = 1;
            }
        }
        
        if (entrada_invalida) {
            continue;
        }

        for (int c = 0; c < 3; c++) {
            n1 += notas[c] * pesos[c];
        }
        for (int c = 3; c < 7; c++) {
            n2 += notas[c] * pesos[c];
        }

        mf = n1 * 0.4 + n2 * 0.6;
        break;
    }

    printf("A media final e: %.2f\n", mf);
 
    return 0;
}