#include <stdio.h>

struct Pessoa {
    char *nome;
};

int main() {
    struct Pessoa pessoa1;

    char nome[] = "Alice";

    pessoa1.nome = nome;

    printf("pessoa1.nome: %s\n", pessoa1.nome); // Isso funcionará

    return 0;
}