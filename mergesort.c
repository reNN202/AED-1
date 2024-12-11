#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }

    while (i < q)
        w[k++] = v[i++];

    while (j < r)
        w[k++] = v[j++];

    for (i = p; i < r; i++)
        v[i] = w[i - p];

    free(w);
}

void Mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercala(p, q, r, v);
    }
}

int main() {
    int tamanho = 20000;
    int incremento = 20000;
    int max_tamanho = 400000;

    FILE *arquivo = fopen("fusao_tempo.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "n,tempo\n");

    srand(time(NULL));
    for (int n = tamanho; n <= max_tamanho; n += incremento) {
        int *vetor = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            vetor[i] = rand();
        }

        clock_t inicio = clock();
        Mergesort(0, n, vetor);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        fprintf(arquivo, "%d,%f\n", n, tempo);
        printf("Fusao - n = %d: %.2f segundos\n", n, tempo);

        free(vetor);
    }

    fclose(arquivo);
    return 0;
}
