#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    char livros[1001][5];

    while (scanf("%d\n", &n) != EOF) {
        memset(livros, 0, sizeof(livros));

        for (int i = 0; i < n; i++) {
            scanf("%s", livros[i]);
        }

        qsort(livros, n, sizeof(char) * 5, comparar);

        for (int i = 0; i < n; i++) {
            printf("%s\n", livros[i]);
        }
    }

    return 0;
}