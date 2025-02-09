#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    int valor;
    struct No *anterior, *proximo;
} No;

typedef struct {
    int tamanho;
    No *frente, *tras;
} Deque;

void inserirFrente(Deque *d, int valor) {
    d->tamanho++;
    No *novaFrente = (No *)malloc(sizeof(No));
    novaFrente->valor = valor;
    novaFrente->proximo = d->frente;
    if (d->frente) d->frente->anterior = novaFrente;
    d->frente = novaFrente;
    if (!d->tras) d->tras = d->frente;
}

void inserirTras(Deque *d, int valor) {
    d->tamanho++;
    No *novoTras = (No *)malloc(sizeof(No));
    novoTras->valor = valor;
    novoTras->anterior = d->tras;
    if (d->tras) d->tras->proximo = novoTras;
    d->tras = novoTras;
    if (!d->frente) d->frente = d->tras;
}

void removerFrente(Deque *d) {
    if (d->tamanho > 0) {
        d->tamanho--;
        No *velhaFrente = d->frente;
        d->frente = d->frente->proximo;
        free(velhaFrente);
    }
}

void removerTras(Deque *d) {
    if (d->tamanho > 0) {
        d->tamanho--;
        No *velhoTras = d->tras;
        d->tras = d->tras->anterior;
        free(velhoTras);
    }
}

int frente(Deque *d) {
    return d->frente->valor;
}

int tras(Deque *d) {
    return d->tras->valor;
}

int tamanho(Deque *d) {
    return d->tamanho;
}

int vazio(Deque *d) {
    return d->tamanho == 0;
}

void inicializar(Deque *d) {
    d->tamanho = 0;
    d->frente = d->tras = NULL;
}

void destruir(Deque *d) {
    while (!vazio(d)) {
        removerFrente(d);
    }
}

int main() {
    int n, primeiro;
    Deque cartas;

    while (scanf("%d", &n) && n) {
        inicializar(&cartas);

        for (int i = 1; i <= n; i++) {
            inserirTras(&cartas, i);
        }

        primeiro = 1;
        printf("Discarded cards: ");
        while (tamanho(&cartas) > 1) {
            if (!primeiro) printf(", ");
            else primeiro = 0;

            printf("%d", frente(&cartas));
            removerFrente(&cartas);
            inserirTras(&cartas, frente(&cartas));
            removerFrente(&cartas);
        }
        printf("\nRemaining card: %d\n", frente(&cartas));

        destruir(&cartas);
    }

    return 0;
}