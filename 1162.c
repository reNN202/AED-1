#include <stdio.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int ordenarVagoes(int *vagoes, int tamanho) {
    int trocas = 0;

    for (int i = 1; i < tamanho; i++) {
        int j = i;
        while (j > 0 && vagoes[j] < vagoes[j - 1]) {
            trocar(&vagoes[j], &vagoes[j - 1]);
            trocas++;
            j--;
        }
    }

    return trocas;
}

int main() {
    int testes, qtdVagoes, vagoes[50];

    scanf("%d", &testes);

    for (int i = 0; i < testes; i++) {
        scanf("%d", &qtdVagoes);

        for (int j = 0; j < qtdVagoes; j++)
            scanf("%d", &vagoes[j]);

        printf("Optimal train swapping takes %d swaps.\n", ordenarVagoes(vagoes, qtdVagoes));
    }

    return 0;
}
