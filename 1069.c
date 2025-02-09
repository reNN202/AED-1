#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct NoPilha {
    char valor;
    struct NoPilha* abaixo;
};

struct Pilha {
    int tamanho;
    struct NoPilha* topo;
};

void empurrar(struct Pilha* p, char valor) {
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

char topo(struct Pilha* p) {
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
    struct Pilha p;
    int N, tam, resposta;
    char expressao[1001];

    scanf("%d\n", &N);

    for (int k = 0; k < N; ++k) {
        scanf("%s\n", expressao);

        resposta = 0;
        inicializar(&p);
        tam = strlen(expressao);

        for (int i = 0; i < tam; ++i) {
            if (expressao[i] == '<') {
                empurrar(&p, '<');
            } else if (expressao[i] == '>') {
                if (!estaVazia(&p)) {
                    ++resposta;
                    remover(&p);
                }
            }
        }

        printf("%d\n", resposta);

        destruir(&p);
    }

    return 0;
}
