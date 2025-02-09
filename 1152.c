#include <stdio.h>
#include <stdlib.h>

struct Aresta {
    int origem, destino, peso;
};

struct Subconjunto {
    int pai;
    int rank;
};

int compararArestas(const void *a, const void *b) {
    return ((struct Aresta *)a)->peso - ((struct Aresta *)b)->peso;
}

int encontrar(struct Subconjunto subconjuntos[], int i) {
    if (subconjuntos[i].pai != i)
        subconjuntos[i].pai = encontrar(subconjuntos, subconjuntos[i].pai);
    return subconjuntos[i].pai;
}

void unir(struct Subconjunto subconjuntos[], int x, int y) {
    int raizX = encontrar(subconjuntos, x);
    int raizY = encontrar(subconjuntos, y);

    if (subconjuntos[raizX].rank < subconjuntos[raizY].rank)
        subconjuntos[raizX].pai = raizY;
    else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank)
        subconjuntos[raizY].pai = raizX;
    else {
        subconjuntos[raizY].pai = raizX;
        subconjuntos[raizX].rank++;
    }
}

int kruskal(struct Aresta arestas[], int V, int E) {
    qsort(arestas, E, sizeof(struct Aresta), compararArestas);

    struct Subconjunto *subconjuntos = (struct Subconjunto *)malloc(V * sizeof(struct Subconjunto));
    for (int v = 0; v < V; v++) {
        subconjuntos[v].pai = v;
        subconjuntos[v].rank = 0;
    }

    int custoTotal = 0, arestasIncluidas = 0;

    for (int i = 0; i < E && arestasIncluidas < V - 1; i++) {
        struct Aresta proximaAresta = arestas[i];

        int x = encontrar(subconjuntos, proximaAresta.origem);
        int y = encontrar(subconjuntos, proximaAresta.destino);

        if (x != y) {
            custoTotal += proximaAresta.peso;
            unir(subconjuntos, x, y);
            arestasIncluidas++;
        }
    }

    free(subconjuntos);
    return custoTotal;
}

int main() {
    int V, E;

    while (1) {
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
            break;

        struct Aresta *arestas = (struct Aresta *)malloc(E * sizeof(struct Aresta));
        int custoOriginal = 0;

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
            custoOriginal += arestas[i].peso;
        }

        int custoMST = kruskal(arestas, V, E);

        printf("%d\n", custoOriginal - custoMST);

        free(arestas);
    }

    return 0;
}
