#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j]; v[j] = v[k]; v[k] = t;
            j++;
        }
    }
    v[r] = v[j]; v[j] = c;
    return j;
}

void Quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa(p, r, v);
        Quicksort(p, j - 1, v);
        Quicksort(j + 1, r, v);
    }
}

int main() {
    int tamanho = 20000;
    int incremento = 20000;
    int max_tamanho = 400000;

    FILE *arquivo = fopen("quick_tempo.csv", "w");
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
        Quicksort(0, n - 1, vetor);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        fprintf(arquivo, "%d,%f\n", n, tempo);
        printf("QuickSort - n = %d: %.2f segundos\n", n, tempo);

        free(vetor);
    }

    fclose(arquivo);
    return 0;
}
