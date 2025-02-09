#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* proximo;
};

typedef struct No No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

void inserir(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void imprimir_tabela(No** tabela, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ->", i);
        No* atual = tabela[i];
        while (atual != NULL) {
            printf(" %d ->", atual->valor);
            atual = atual->proximo;
        }
        printf(" \\\n");
    }
}

void liberar_tabela(No** tabela, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        No* atual = tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    int testes;
    scanf("%d", &testes);

    while (testes--) {
        int tamanho, elementos;
        scanf("%d %d", &tamanho, &elementos);

        No* tabela[tamanho];
        for (int i = 0; i < tamanho; i++) {
            tabela[i] = NULL;
        }

        for (int i = 0; i < elementos; i++) {
            int chave;
            scanf("%d", &chave);
            inserir(&tabela[chave % tamanho], chave);
        }

        imprimir_tabela(tabela, tamanho);

        if (testes > 0) {
            printf("\n");
        }

        liberar_tabela(tabela, tamanho);
    }

    return 0;
}
