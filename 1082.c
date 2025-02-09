#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visited[26];
int graph[26][26];
char lista[26];

int contador;
int vertices, arestas;

void busca(int v);
int comparar(const void *a, const void *b);

int main() {
    char a, b;
    int i, j, testes;
    int caso = 0;

    scanf("%d", &testes);

    while (testes--) {
        scanf("%d %d", &vertices, &arestas);

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        for (i = 0; i < arestas; ++i) {
            scanf(" %c %c", &a, &b);
            graph[a - 'a'][b - 'a'] = 1;
            graph[b - 'a'][a - 'a'] = 1;
        }

        printf("Case #%d:\n", ++caso);
        int componentes = 0;

        for (i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                componentes++;
                busca(i);
                qsort(lista, contador, sizeof(char), comparar);
                for (j = 0; j < contador; ++j) {
                    printf("%c,", lista[j] + 'a');
                }
                printf("\n");
                contador = 0;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}

void busca(int v) {
    visited[v] = 1;
    lista[contador++] = v;
    for (int i = 0; i < vertices; ++i) {
        if (graph[v][i] && !visited[i]) {
            busca(i);
        }
    }
}

int comparar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}