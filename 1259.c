#include <stdlib.h>
#include <stdio.h>

int comparar(const void *a, const void *b) {
    int primeiro = *(int *)a, segundo = *(int *)b;

    if (primeiro % 2 == 0 && segundo % 2 == 0)
        return primeiro - segundo;
    if (primeiro % 2 == 0)
        return -1;
    if (segundo % 2 == 0)
        return 1;
    return segundo - primeiro;
}

int main() {
    int quantidade, numeros[100000];

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++)
        scanf("%d", &numeros[i]);

    qsort(numeros, quantidade, sizeof(int), comparar);

    for (int i = 0; i < quantidade; i++)
        printf("%d\n", numeros[i]);

    return 0;
}
