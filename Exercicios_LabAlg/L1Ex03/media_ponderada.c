#include <stdio.h>

int main(int argc, char *argv[]) {
    float nota1,nota2,nota3,nota4,media;

    while (1) {
        printf("Qual a nota das suas atividades presenciais ?\n");
        scanf("%f",&nota1);

        printf("Qual a nota das suas atividades online ?\n");
        scanf("%f",&nota2);

        printf("Qual a nota da sua prova 1 ?\n");
        scanf("%f",&nota3);

        printf("Qual a nota da sua prova 2 ?\n");
        scanf("%f",&nota4);

        // Processamento
        media = nota1 * 0.1 + nota2 * 0.2 + nota3 * 0.3 + nota4 * 0.4;

        if (media > 10 || nota1 > 10 || nota2 > 10 || nota3 > 10 || nota4 > 10) {
            printf("Digite notas validas !\n");
        } else {
            break;
        }
    }
    
    printf("%.2f", media);
}