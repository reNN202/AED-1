#include <stdlib.h>
#include <stdio.h>

int inversoes;

int comparar(int a, int b) {
    return a - b;
}

void mesclar(int *vetor, int inicio, int meio, int fim) {
    int *aux = (int *)malloc((fim - inicio) * sizeof(int));
    int i = 0, i1 = inicio, i2 = meio, n1 = meio, n2 = fim;

    while (i1 < n1 && i2 < n2) {
        if (comparar(vetor[i1], vetor[i2]) < 0) {
            aux[i++] = vetor[i1++];
        } else {
            aux[i++] = vetor[i2++];
            inversoes += (n1 - i1);
        }
    }

    while (i1 < n1) aux[i++] = vetor[i1++];
    while (i2 < n2) aux[i++] = vetor[i2++];

    for (int i = inicio; i < fim; ++i) {
        vetor[i] = aux[i - inicio];
    }

    free(aux);
}

void ordenarMerge(int *vetor, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;

        ordenarMerge(vetor, inicio, meio);
        ordenarMerge(vetor, meio, fim);
        mesclar(vetor, inicio, meio, fim);
    }
}

int main() {
    int N, *vetor;

    while (scanf("%d", &N)) {
        if (!N) break;

        vetor = (int *)malloc(N * sizeof(int));

        for (int i = 0; i < N; ++i) {
            scanf("%d", &vetor[i]);
        }

        inversoes = 0;
        ordenarMerge(vetor, 0, N);

        printf("%s\n", (inversoes % 2) ? "Marcelo" : "Carlos");

        free(vetor);
    }

    return 0;
}
