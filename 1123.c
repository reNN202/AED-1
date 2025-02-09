#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INFINITO 100000
#define TAM_MAX 101010

int visitado[TAM_MAX];
int distancia[TAM_MAX];

typedef struct No {
    int destino, peso;
    struct No *proximo;
} No;

typedef struct Grafo {
    No *adjacente;
} Grafo;

Grafo *criar_grafo(int);
No *criar_no(int, int);
void dijkstra(Grafo *, int, int);
void adicionar_aresta(Grafo *, int, int, int);

int main() {
    int i, cidades, rotas, capital, origem, a, b, peso;

    while (scanf("%d %d %d %d", &cidades, &rotas, &capital, &origem), (capital && cidades && rotas && origem)) {
        Grafo *grafo = criar_grafo(cidades + 1);

        for (i = 0; i < rotas; ++i) {
            scanf("%d %d %d", &a, &b, &peso);

            if ((a >= capital && b >= capital) || ((a < capital) && (b < capital) && (abs(a - b) == 1))) {
                adicionar_aresta(grafo, a, b, peso);
                adicionar_aresta(grafo, b, a, peso);
            }
            if (a >= capital && b < capital)
                adicionar_aresta(grafo, b, a, peso);
            if (b >= capital && a < capital)
                adicionar_aresta(grafo, a, b, peso);
        }

        dijkstra(grafo, origem, cidades);
        printf("%d\n", distancia[capital - 1]);
    }

    return 0;
}

void dijkstra(Grafo *g, int inicio, int tam) {
    No *k;
    int i, j, v;

    for (i = 0; i < tam; ++i)
        distancia[i] = INFINITO;

    memset(visitado, false, sizeof(visitado));
    distancia[inicio] = 0;

    for (i = 0; i < tam; ++i) {
        v = -1;

        for (j = 0; j < tam; ++j)
            if (!visitado[j] && (v == -1 || distancia[j] < distancia[v]))
                v = j;

        if (distancia[v] == INFINITO)
            break;

        visitado[v] = true;

        for (k = g->adjacente[v].proximo; k != NULL; k = k->proximo) {
            int destino = k->destino;
            int peso = k->peso;

            if (distancia[v] + peso < distancia[destino])
                distancia[destino] = distancia[v] + peso;
        }
    }
}

Grafo *criar_grafo(int tam) {
    int i;
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    g->adjacente = (No *) malloc(sizeof(No) * (tam + 1));

    for (i = 0; i < tam; ++i)
        g->adjacente[i].proximo = NULL;

    return g;
}

No *criar_no(int destino, int peso) {
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->destino = destino;
    novo_no->peso = peso;
    novo_no->proximo = NULL;
    return novo_no;
}

void adicionar_aresta(Grafo *g, int origem, int destino, int peso) {
    No *novo_no = criar_no(origem, peso);
    novo_no->proximo = g->adjacente[destino].proximo;
    g->adjacente[destino].proximo = novo_no;
}
