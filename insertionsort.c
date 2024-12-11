#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercao(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--)
            v[i + 1] = v[i];
        v[i + 1] = x;
    }
}

int main() {
    int tamanho = 20000;
    int incremento = 20000;
    int max_tamanho = 400000;

    FILE *arquivo = fopen("insercao_tempo.csv", "w");
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
        Insercao(n, vetor);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        fprintf(arquivo, "%d,%f\n", n, tempo);
        printf("Insercao - n = %d: %.2f segundos\n", n, tempo);

        free(vetor);
    }

    fclose(arquivo);
    return 0;
}
