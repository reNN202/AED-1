#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int topo;
    long long int elementos[99999];
} Pilha;

Pilha criarPilha() {
    Pilha p;
    p.topo = -1;
    return p;
}

bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, long long int valor) {
    p->topo++;
    p->elementos[p->topo] = valor;
}

void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    } else {
        printf("EMPTY\n");
    }
}

long long menorValor(Pilha *p) {
    if (estaVazia(p)) return -1;

    long long menor = p->elementos[0];
    for (int i = 1; i <= p->topo; i++) {
        if (p->elementos[i] < menor) {
            menor = p->elementos[i];
        }
    }
    return menor;
}

int main() {
    unsigned int quantidade;
    char operacao[10];
    long long int numero, resultado;

    scanf("%u", &quantidade);
    Pilha p = criarPilha();

    while (quantidade--) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%lld", &numero);
            empilhar(&p, numero);
        } else if (strcmp(operacao, "POP") == 0) {
            desempilhar(&p);
        } else {
            resultado = menorValor(&p);
            if (resultado == -1) {
                printf("EMPTY\n");
            } else {
                printf("%lld\n", resultado);
            }
        }
    }

    return 0;
}