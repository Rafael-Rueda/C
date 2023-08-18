#include <stdio.h>

int main(int argc, char *argv[]) {
    
    float space, price, km_l;

    printf("Digite a distancia a ser percorrida:\n");
    scanf("%f", &space);

    printf("Digite o preco por litro do combustivel:\n");
    scanf("%f", &price);

    printf("Digite a quilometragem que o veiculo faz por litro:\n");
    scanf("%f", &km_l);

    float liters;
    float cost;

    liters = space / km_l;
    cost = liters * price;

    printf("Voce precisa de %.2f litros de combustivel para percorrer a distancia fornecida.\n", liters);
    printf("Voce ira gastar %.2f reais nessa viagem.", cost);

    return 0;
}
