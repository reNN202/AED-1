#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Camiseta {
    char nome[100], cor[10], tamanho[10];
};

int comparar(const void *a, const void *b) {
    struct Camiseta *c1 = (struct Camiseta *)a;
    struct Camiseta *c2 = (struct Camiseta *)b;

    int corCmp = strcmp(c1->cor, c2->cor);
    if (corCmp == 0) {
        int tamCmp = strcmp(c2->tamanho, c1->tamanho);
        return (tamCmp == 0) ? strcmp(c1->nome, c2->nome) : tamCmp;
    }
    return corCmp;
}

int main() {
    int qtd;
    struct Camiseta camisetas[60];

    while (scanf("%d", &qtd) && qtd) {
        for (int i = 0; i < qtd; i++) {
            getchar(); 
            scanf("%[^\n]", camisetas[i].nome);
            scanf("%s %s", camisetas[i].cor, camisetas[i].tamanho);
        }

        qsort(camisetas, qtd, sizeof(struct Camiseta), comparar);

        for (int i = 0; i < qtd; i++)
            printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);

        printf("\n");
    }

    return 0;
}
