#include <stdlib.h>
#include <stdio.h>

struct NoPilha {
    int valor;
    struct NoPilha* abaixo;
};

struct Pilha {
    int tamanho;
    struct NoPilha* topo;
};

void empurrar(struct Pilha* p, int valor) {
    p->tamanho += 1;
    struct NoPilha* novoTopo = (struct NoPilha*) malloc(sizeof(struct NoPilha));

    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void remover(struct Pilha* p) {
    if (p->tamanho > 0) {
        p->tamanho -= 1;
        struct NoPilha* topoAntigo = p->topo;
        p->topo = p->topo->abaixo;
        free(topoAntigo);
    }
}

int topo(struct Pilha* p) {
    return p->topo->valor;
}

int tamanho(struct Pilha* p) {
    return p->tamanho;
}

int estaVazia(struct Pilha* p) {
    return p->tamanho == 0;
}

void inicializar(struct Pilha* p) {
    p->tamanho = 0;
    p->topo = NULL;
}

void destruir(struct Pilha* p) {
    while (!estaVazia(p)) {
        remover(p);
    }
}

int main() {
    int N, x;
    struct Pilha A, estacao, B;

    while (scanf("%d", &N) != EOF) {
        if (N == 0) break;

        while (scanf("%d", &x)) {
            if (x == 0) {
                printf("\n");
                break;
            }

            inicializar(&A);
            inicializar(&estacao);
            inicializar(&B);

            empurrar(&A, x);
            empurrar(&B, 1);
            for (int i = 2; i <= N; ++i) {
                scanf("%d", &x);
                empurrar(&A, x);
                empurrar(&B, i);
            }

            while (!estaVazia(&A) || !estaVazia(&estacao) || !estaVazia(&B)) {
                if (!estaVazia(&A) && !estaVazia(&B) && topo(&A) == topo(&B)) {
                    remover(&A);
                    remover(&B);
                } else if (!estaVazia(&estacao) && !estaVazia(&B) && topo(&estacao) == topo(&B)) {
                    remover(&estacao);
                    remover(&B);
                } else if (!estaVazia(&A)) {
                    empurrar(&estacao, topo(&A));
                    remover(&A);
                } else {
                    break;
                }
            }

            if (estaVazia(&A) && estaVazia(&estacao) && estaVazia(&B)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            destruir(&A);
            destruir(&estacao);
            destruir(&B);
        }
    }

    return 0;
}
